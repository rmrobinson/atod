package goalgo

import "testing"

func TestLCS1(t *testing.T) {
	first := "ABCDGH"
	second := "AEDFHR"
	result := "ADH"

	l := Lcs(len(first), first, len(second), second)

	if l != len(result) {
		t.Errorf("lcs length incorrect, expected %d got %d", len(result), l)
	}
}
