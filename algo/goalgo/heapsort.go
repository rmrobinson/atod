package goalgo

func Heapsort(arr []int) {
	heapSize := buildMaxHeap(arr[0:])

	for i := len(arr) - 1; i > 0; i-- {
		tmp := arr[0]
		arr[0] = arr[i]
		arr[i] = tmp

		heapSize--

		maxHeapify(arr[0:], 0, heapSize)
	}
}

func buildMaxHeap(arr []int) int {
	heapSize := len(arr)

	for i := len(arr) / 2; i >= 0; i-- {
		maxHeapify(arr, i, heapSize)
	}

	return heapSize
}

func maxHeapify(arr []int, idx int, heapSize int) {
	l := left(idx)
	r := right(idx)

	// Figure out the index of the largest value in idx, left, and right
	idxOfLargest := idx

	if l < heapSize && arr[l] > arr[idx] {
		idxOfLargest = l
	}
	if r < heapSize && arr[r] > arr[idxOfLargest] {
		idxOfLargest = r
	}

	// If the largest isn't the current node, swap with the left or right then recurse
	if idxOfLargest != idx {
		tmp := arr[idx]
		arr[idx] = arr[idxOfLargest]
		arr[idxOfLargest] = tmp

		maxHeapify(arr, idxOfLargest, heapSize)
	}
}

func left(idx int) int {
	if idx == 0 {
		return 1
	}

	return 2 * idx
}

func right(idx int) int {
	if idx == 0 {
		return 2
	}

	return 2 * idx + 1
}
