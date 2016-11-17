package goalgo

import (
	"strings"
)

type node struct {
	chars map[rune]*node
	p *node
	r rune
}

type Trie struct {
	root node
}

func (t *Trie) Add(input string) {
	word := strings.ToLower(input)
	curr := t.root

	for i := 0; i < len(word); i++ {
		if curr == nil {
			curr = &node{}

		}
	}
}

func (t *Trie) Contains(word string) {

}