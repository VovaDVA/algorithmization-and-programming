package main

import (
	"fmt"
)

func main() {
	var n int
	fmt.Scan(&n)
	fmt.Print(n/5000, n%5000/1000, n%5000%1000/500, n%5000%1000%500/200, n%5000%1000%500%200/100)
}
