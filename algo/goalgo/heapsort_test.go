package goalgo

import "testing"

func TestHeapsort(t *testing.T) {
	for _, c := range Cases {
		in := make([]int, len(c.in))
		copy(in, c.in)

		Heapsort(in)

		if !CheckArr(in, c.want) {
			t.Errorf("heapsort: checkArr(%v) != %v", in, c.want)
		}
	}
}

