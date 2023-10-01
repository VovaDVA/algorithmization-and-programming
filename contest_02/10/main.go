package main

import (
	"fmt"
)

func Abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func shift(data []int, steps int) {
	newData := make([]int, len(data))
	copy(newData, data)

	for i := 0; i < 10; i++ {
		if steps <= 0 {
			data[i] = newData[(i-steps)%10]
		} else {
			if i-steps < 0 {
				data[i] = newData[(10-Abs(i-steps)%10)%10]
			} else {
				data[i] = newData[i-steps]
			}
		}
	}
}

func main() {
	var steps int
	fmt.Scan(&steps)

	var data [10]int
	for index := range data {
		fmt.Scan(&data[index])
	}

	shift(data[:], steps)
	for _, value := range data {
		fmt.Printf("%d ", value)
	}
}
