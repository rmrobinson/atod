package goalgo

import (
	"testing"
)

const (
	InOrderWalkRet = "0, 1, 2, 3, 4, 5, 6, 7, 8, 9"
	PrefixWalkRet = "0, 1, 2, 3, 4, 5, 6, 7, 8, 9"
	PostfixWalkRet = "9, 8, 7, 6, 5, 4, 3, 2, 1, 0"
)

func TestBSTInsertion(t *testing.T) {
	var bst = &BST{}

	for i := 0; i < 10; i++ {
		bst.Insert(i)
	}

	inorder := bst.Walk(InOrderWalk)

	if (inorder != InOrderWalkRet) {
		t.Errorf("bst inorder walk: incorrect result: %v", inorder)
	}

	preorder := bst.Walk(PrefixWalk)

	if (preorder != PrefixWalkRet) {
		t.Errorf("bst prefix walk: incorrect result: %v", preorder)
	}

	postorder := bst.Walk(PostfixWalk)

	if (postorder != PostfixWalkRet) {
		t.Errorf("bst postfix walk: incorrect result: %v", postorder)
	}

	target := 3

	if (!bst.Search(target)) {
		t.Errorf("bst search: couldn't find %v", target)
	}


	largest := bst.FindMaximum()

	if (largest != 9) {
		t.Errorf("bst largest incorrect: %v", largest)
	}

	secondLargest, err := bst.FindSecondLargest()

	if err != nil {
		t.Errorf("bst second largest: couldn't find second largest: %v", err)
	} else if (secondLargest != 8) {
		t.Errorf("bst second largest incorrect: %v", secondLargest)
	}
}