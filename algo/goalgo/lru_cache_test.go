package goalgo

import "testing"

func TestLruCache1(t *testing.T) {
	c := newLru(3)

	c.insert("test1", 1)
	c.insert("test2", 2)
	c.insert("test3", 3)
	c.insert("test4", 4)

	_, err1 := c.get("test1")
	val4, err4 := c.get("test4")
	val2, err2 := c.get("test2")
	val3, err3 := c.get("test3")

	if err1 != errCacheRecordNotFound {
		t.Error("cache should have evicted val1")
	}
	if err2 != nil || val2 != 2 {
		t.Error("cache val2 incorrect or missing")
	}
	if err3 != nil || val3 != 3 {
		t.Error("cache val3 incorrect or missing")
	}
	if err4 != nil || val4 != 4 {
		t.Error("cache val4 incorrect or missing")
	}
	if c.head.val != 3 {
		t.Error("cache head pointer incorrect")
	}
	if c.tail.val != 4 {
		t.Error("cache tail pointer incorrect")
	}
}

func TestLruCache2(t *testing.T) {
	c := newLru(3)

	c.insert("test1", 1)

	val1, err1 := c.get("test1")
	_, err2 := c.get("test2")

	if err2 != errCacheRecordNotFound {
		t.Error("cache should not have val2")
	}
	if err1 != nil || val1 != 1 {
		t.Error("cache val1 incorrect or missing")
	}
}
