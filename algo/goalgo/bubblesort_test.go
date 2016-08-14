package goalgo

import "testing"

func TestBubblesort(t *testing.T) {
	for _, c := range Cases {
		in := make([]int, len(c.in))
		copy(in, c.in)

		got := Bubblesort(in)

		if !CheckArr(got, c.want) {
			t.Errorf("bubblesort: checkArr(%v) != %v", got, c.want)
		}
	}
}
