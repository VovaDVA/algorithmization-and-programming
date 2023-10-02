package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
)

func isLucky(code string) bool {
	sum1 := 0
	sum2 := 0

	for i := 0; i < 3; i++ {
		n, err := strconv.Atoi(string(code[i]))
		sum1 += n
		if err != nil {
			log.Fatal(err)
		}
	}

	for i := 3; i < 6; i++ {
		n, err := strconv.Atoi(string(code[i]))
		sum2 += n
		if err != nil {
			log.Fatal(err)
		}
	}

	return sum1 == sum2
}

func main() {
	number, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isLucky(number[:len(number)-1]) { // Обрезаем \n в конце строки
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
