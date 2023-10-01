package main

import (
	"fmt"
)

func main() {
	var x int
	fmt.Scan(&x)
	fmt.Print(collats(x))
}

func collats(x int) int {
	var cnt int

	for x != 1 {
		if x%2 == 0 {
			x /= 2
		} else {
			x = 3*x + 1
		}
		cnt++
	}

	return cnt
}
