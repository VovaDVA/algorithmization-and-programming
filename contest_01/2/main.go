package main

import (
	"fmt"
	"math"
)

func main() {
	fmt.Print(0.5*365, math.Ceil(0.5*365/32), math.Ceil(0.5*365/20))
}

