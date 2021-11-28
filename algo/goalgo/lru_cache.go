package goalgo

import (
	"errors"
	"sync"
)

var (
	errCacheRecordNotFound = errors.New("cache record not found")
	errCacheMalformed      = errors.New("cache malformed")
)

type node struct {
	prev *node
	next *node

	key string
	val interface{}
}

type lru struct {
	m       sync.Mutex
	records map[string]*node

	head *node
	tail *node

	maxSize int
}

func newLru(maxSize int) *lru {
	return &lru{
		records: map[string]*node{},
		head:    nil,
		tail:    nil,
		maxSize: maxSize,
	}
}

func (l *lru) insert(key string, val interface{}) {
	n := &node{
		prev: nil,
		next: l.head,
		val:  val,
		key:  key,
	}

	l.m.Lock()
	defer l.m.Unlock()

	l.records[key] = n

	if l.head == nil {
		l.head = n
	} else {
		l.head.prev = n
		l.head = n
	}

	if l.tail == nil {
		l.tail = n
	}

	if len(l.records) > l.maxSize {
		toDelKey := l.tail.key
		l.tail = l.tail.prev
		l.tail.next = nil
		delete(l.records, toDelKey)
	}
}

func (l *lru) get(key string) (interface{}, error) {
	l.m.Lock()
	defer l.m.Unlock()

	if n, found := l.records[key]; found {
		// We don't have to manipulate head/tail since we only have a single record
		if len(l.records) == 1 {
			return n.val, nil
		}

		// We have at least 2 records which means tail != head
		if l.tail == l.head {
			return nil, errCacheMalformed
		}

		// If we already have the first item, we don't need to manipulate anything
		if l.head == n {
			return n.val, nil
		}

		// Remove the element from its peers
		if n.next != nil {
			n.next.prev = n.prev
		}
		if n.prev != nil {
			n.prev.next = n.next
		}

		// Reset the head/tail pointers as appropriate
		if l.head != n {
			n.next = l.head
			l.head.prev = n
		}
		if l.tail == n {
			l.tail = n.prev
		}

		l.head = n
		n.prev = nil
		return n.val, nil
	}
	return nil, errCacheRecordNotFound
}
