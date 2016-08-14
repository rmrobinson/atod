package goalgo

func Mergesort(arr []int) []int {
	return internalSort(arr)
}

func internalSort(arr []int) []int {
	if len(arr) < 2 {
		return arr
	}

	sortedLeft := internalSort(arr[:len(arr)/2])
	sortedRight := internalSort(arr[len(arr)/2:])

	leftIndex := 0
	rightIndex := 0

	output := make([]int, len(arr))
	outputIndex := 0

	for leftIndex < len(sortedLeft) && rightIndex < len(sortedRight) {
		if sortedLeft[leftIndex] < sortedRight[rightIndex] {
			output[outputIndex] = sortedLeft[leftIndex]
			outputIndex++
			leftIndex++
		} else {
			output[outputIndex] = sortedRight[rightIndex]
			outputIndex++
			rightIndex++
		}
	}

	for ; leftIndex < len(sortedLeft); leftIndex++ {
		output[outputIndex] = sortedLeft[leftIndex]
		outputIndex++
	}

	for ; rightIndex < len(sortedRight); rightIndex++ {
		output[outputIndex] = sortedRight[rightIndex]
		outputIndex++
	}

	return output
}
