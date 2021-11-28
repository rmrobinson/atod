package goalgo

func backpack(values []int, weights []int, itemIdx int, maxWeight int) int {
	if maxWeight < 0 {
		return -100000
	}
	// No more space or no more items
	if maxWeight == 0 || itemIdx < 0 {
		return 0
	}

	// include the item in the backpack
	include := values[itemIdx] + backpack(values, weights, itemIdx-1, maxWeight-weights[itemIdx])

	exclude := backpack(values, weights, itemIdx-1, maxWeight)

	if include > exclude {
		return include
	}
	return exclude
}
