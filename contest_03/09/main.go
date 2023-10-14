package main

import (
	"fmt"
	"sort"
)

func main() {
	var n, x int
	fmt.Scan(&n, &x)

	nums := make([]int, n)
	indexes := make(map[int]int)

	for i := 0; i < n; i++ {
		fmt.Scan(&nums[i])
		indexes[nums[i]] = i
	}

	ans := []int{}

	for i, num := range nums {
		d := x - num
		if index, ok := indexes[d]; ok && index != i {
			ans = append(ans, num, nums[index])
			break
		}
	}

	if len(ans) == 0 {
		fmt.Println(0, 0)
	} else {
		sort.Ints(ans)
		fmt.Println(ans[0], ans[1])
	}
}
