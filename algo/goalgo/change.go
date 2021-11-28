package goalgo

import (
	"errors"
)

var (
	errExactChangeUnavailable = errors.New("exact change unachievable")
)

func change(denominations []int, value int) (int, error) {
	if value == 0 {
		return 0, nil
	}

	biggestMatching := -1
	for _, denom := range denominations {
		if denom <= value {
			if denom > biggestMatching {
				biggestMatching = denom
			}
		}
	}

	if biggestMatching < 0 {
		return 0, errExactChangeUnavailable
	}

	c, err := change(denominations, value-biggestMatching)

	if err != nil {
		return 0, err
	}
	return c + 1, nil
}
