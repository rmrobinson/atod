package goalgo

import (
	"fmt"
	"strings"
	"strconv"
)

type node struct {
	key int

	parent *node
	left *node
	right *node
}

type BST struct {
	root *node
}

func (b *BST) Search(i int) bool {
	n := search(b.root, i)

	if n == nil {
		return false
	} else if (n.key != i) {
		return false;
	}

	return true
}

func (b *BST) FindMaximum() (int) {
	n := b.root

	for {
		if (n.right == nil) {
			return n.key
		} else {
			n = n.right
		}
	}
}

func (b *BST) FindSecondLargest() (int, error) {
	var prev *node = nil
	n := b.root

	for {
		if (n.right == nil) {
			if prev != nil {
				return prev.key, nil
			} else {
				return -1, fmt.Errorf("Unable to find second largest with only 1 node")
			}
		}

		prev = n
		n = n.right
	}
}

func search(n *node, i int) *node {
	if n == nil || n.key == i {
		return n
	}

	if i < n.key {
		return search(n.left, i)
	} else {
		return search(n.right, i)
	}
}

func (b *BST) Insert(value int) {
	var n = &node{key: value}

	b.insert(n)
}

func (b *BST) insert(z *node) {
	var y *node = nil
	x := b.root

	for ; x != nil ; {
		y = x

		if z.key < x.key {
			x = x.left
		} else {
			x = x.right
		}
	}

	z.parent = y

	if y == nil {
		b.root = z
	} else if z.key < y.key {
		y.left = z
	} else {
		y.right = z
	}
}

type WalkType int
const (
	InOrderWalk WalkType = iota
	PrefixWalk
	PostfixWalk
)

func (b *BST) Walk(t WalkType) string {
	var ret string
	if t == InOrderWalk {
		ret = walkInorder(b.root)
	} else if t == PrefixWalk {
		ret = walkPrefix(b.root)
	} else if t == PostfixWalk {
		ret = walkPostfix(b.root)
	}

	return strings.TrimRight(ret, ", ")
}

func walkInorder(n *node) string {
	var ret string
	if n != nil {
		ret += walkInorder(n.left)
		ret += strconv.Itoa(n.key) + ", "
		ret += walkInorder(n.right)
	}

	return ret;
}

func walkPrefix(n *node) string {
	var ret string
	if n != nil {
		ret += strconv.Itoa(n.key) + ", "

		ret += walkPrefix(n.left)
		ret += walkPrefix(n.right)
	}

	return ret
}

func walkPostfix(n *node) string {
	var ret string

	if n != nil {
		ret += walkPostfix(n.left)
		ret += walkPostfix(n.right)

		ret += strconv.Itoa(n.key) + ", "
	}

	return ret
}