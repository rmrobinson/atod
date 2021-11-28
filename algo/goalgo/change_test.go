package goalgo

import "testing"

func TestChange1(t *testing.T) {
	denominations := []int{5, 10, 25, 100, 200}

	cases := []struct {
		value int
		ret   int
		err   error
	}{
		{
			25, 1, nil,
		},
		{
			15, 2, nil,
		},
		{
			20, 2, nil,
		},
		{
			95, 5, nil,
		},
		{
			22, 0, errExactChangeUnavailable,
		},
	}

	for _, tt := range cases {
		ret, err := change(denominations, tt.value)
		if ret != tt.ret {
			t.Errorf("unexpected count, expected %d got %d", tt.ret, ret)
		} else if err != tt.err {
			t.Errorf("unexpected error, expected %s got %s", tt.err, err)
		}
	}
}
