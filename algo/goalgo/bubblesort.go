package goalgo

func Bubblesort(arr []int) []int {
	swapped := true

	// Repeat until we've gone through the array without swapping anything
	for swapped {
		swapped = false

		for i := 1; i < len(arr); i++ {
			if arr[i-1] > arr[i] {
				tmp := arr[i-1]
				arr[i-1] = arr[i]
				arr[i] = tmp
				swapped = true
			}
		}
	}

	return arr
}
