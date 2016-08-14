package goalgo

import "testing"

func TestMergesort(t *testing.T) {
	for _, c := range Cases {
		in := make([]int, len(c.in))
		copy(in, c.in)

		got := Mergesort(in)

		if !CheckArr(got, c.want) {
			t.Errorf("mergesort: checkArr(%v) != %v", got, c.want)
		}
	}
}
