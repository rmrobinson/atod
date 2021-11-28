package goalgo

import "testing"

func TestBackpack(t *testing.T) {
	values := []int{20, 5, 10, 40, 15, 25}
	weights := []int{1, 2, 3, 8, 7, 4}
	maxWeight := 10

	ret := backpack(values, weights, len(values)-1, maxWeight)

	if ret != 60 {
		t.Errorf("should have had backpack of 60, got %d instead", ret)
	}
}
