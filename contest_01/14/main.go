package main

import (
	"fmt"
)

func main() {
	var row, col int
	fmt.Scan(&row, &col)
	table(row, col)
}

func table(row, col int) {

	fmt.Print("    |")

	for i := 1; i <= col; i++ {
		if i < 10 {
			fmt.Print("   ", i)
		} else {
			fmt.Print("  ", i)
		}
	}

	fmt.Println()

	fmt.Print("   ")

	for i := -2; i < col*4; i++ {
		fmt.Print("-")
	}

	fmt.Println()

	for i := 1; i <= row; i++ {
		if i < 10 {
			fmt.Print("   ", i, "|")
		} else {
			fmt.Print("  ", i, "|")
		}

		for j := 1; j <= col; j++ {
			if i*j < 10 {
				fmt.Print("   ")
			} else if i*j >= 10 && i*j < 100 {
				fmt.Print("  ")
			} else {
				fmt.Print(" ")
			}
			fmt.Print(i * j)
		}
		fmt.Println()
	}
}
