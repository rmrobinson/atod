package goalgo

var Cases = []struct {
	in, want []int
}{
	{[]int{10, 2, 5}, []int{2, 5, 10}},
	{[]int{1, 2, 3, 10, 5}, []int{1, 2, 3, 5, 10}},
	{[]int{1}, []int{1}},
	{[]int{}, []int{}},
	{[]int{5, 4, 3, 2, 1}, []int{1, 2, 3, 4, 5}},
	{[]int{3, 4, 3, 6, 1, 3}, []int{1, 3, 3, 3, 4, 6}},
}

func CheckArr(left, right []int) bool {
	if len(left) != len(right) {
		return false
	}

	for i, leftx := range left {
		if right[i] != leftx {
			return false
		}
	}

	return true
}
