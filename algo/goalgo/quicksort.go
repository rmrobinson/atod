package goalgo

func Quicksort(arr []int, p int, r int) []int {
	if p < r {
		q := partition(arr, p, r)

		Quicksort(arr, p, q-1)
		Quicksort(arr, q+1, r)
	}

	return arr
}

func partition(arr []int, p int, r int) int {
	x := arr[r]
	i := p - 1

	tmp := 0

	for j := p; j <= r-1; j++ {
		if arr[j] <= x {
			i += 1
			tmp = arr[i]
			arr[i] = arr[j]
			arr[j] = tmp
		}
	}

	tmp = arr[i+1]
	arr[i+1] = arr[r]
	arr[r] = tmp

	return i + 1
}

func HoareQuicksort(arr []int, p int, r int) []int {
	if p < r {
		q := hoarePartition(arr, p, r)

		Quicksort(arr, p, q)
		Quicksort(arr, q+1, r)
	}

	return arr
}

func hoarePartition(arr []int, p int, r int) int {
	x := arr[p]
	i := p - 1
	j := r + 1

	for {
		for j--; arr[j] > x; j-- {
		}
		for i++; arr[i] < x; i++ {
		}

		// We should have the proper values for i and j now
		if i < j {
			tmp := arr[i]
			arr[i] = arr[j]
			arr[j] = tmp
		} else {
			return j
		}
	}
}
