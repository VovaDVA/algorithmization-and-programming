package main

import (
	"fmt"
)

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)
	fmt.Print(max(a, b, c))
}

func max(a, b, c int) int {
	if a > b {
		if a > c {
			return a
		} else {
			return c
		}
	} else {
		if b > c {
			return b
		} else {
			return c
		}
	}
}
