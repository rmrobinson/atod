package goalgo

import "fmt"

func Lcs(firstLen int, first string, secondLen int, second string) int {
	lookup := map[string]int{}

	return lcsImpl(firstLen, first, secondLen, second, lookup)
}

func lcsImpl(firstLen int, first string, secondLen int, second string, lookup map[string]int) int {
	if firstLen == 0 || secondLen == 0 {
		return 0
	}

	key := fmt.Sprintf("%d-%d", firstLen, secondLen)
	if len, found := lookup[key]; found {
		return len
	}

	if first[firstLen-1] == second[secondLen-1] {
		lastLen := Lcs(firstLen-1, first, secondLen-1, second)
		lookup[key] = lastLen + 1
		return lastLen + 1
	} else {
		leftLen := Lcs(firstLen-1, first, secondLen, second)
		rightLen := Lcs(firstLen, first, secondLen-1, second)

		if leftLen > rightLen {
			lookup[key] = leftLen
			return leftLen
		} else {
			lookup[key] = rightLen
			return rightLen
		}
	}
}
