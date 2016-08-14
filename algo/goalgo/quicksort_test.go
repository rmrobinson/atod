package goalgo

import "testing"

func TestQuicksort(t *testing.T) {
	for _, c := range Cases {
		in := make([]int, len(c.in))
		copy(in, c.in)

		got := Quicksort(in, 0, len(in)-1)

		if !CheckArr(got, c.want) {
			t.Errorf("quicksort: checkArr(%v) != %v", got, c.want)
		}
	}
}

func TestHoareQuicksort(t *testing.T) {
	for _, c := range Cases {
		in := make([]int, len(c.in))
		copy(in, c.in)

		got := HoareQuicksort(in, 0, len(in)-1)

		if !CheckArr(got, c.want) {
			t.Errorf("hoare quicksort: checkArr(%v) != %v", got, c.want)
		}
	}
}
