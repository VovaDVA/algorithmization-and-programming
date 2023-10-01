package main

import (
	"fmt"
	"math"
)

func main() {
	var n int
	fmt.Scanln(&n)

	numbers := []float64{}

	for i := 0; i < n; i++ {
		var m float64
		fmt.Scan(&m)
		numbers = append(numbers, m)
	}

	fmt.Print(numbers[0], ".0 ")

	for i := 1; i < len(numbers)-1; i++ {
		new := (numbers[i-1] + numbers[i] + numbers[i+1]) / 3
		if new == math.Round(new) {
			fmt.Print(new, ".0 ")
		} else {
			fmt.Print(new, " ")
		}

	}

	fmt.Print(numbers[len(numbers)-1], ".0")

}
