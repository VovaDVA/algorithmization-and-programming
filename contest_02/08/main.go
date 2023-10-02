package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func isPalindrome(code string) bool {
	str := ""

	for i := 0; i < len(code); i++ {
		if !strings.Contains("~!@#%^&*() ", string(code[i])) {
			str += string(code[i])
		}
	}

	str = strings.ToLower(str)

	n := len(str)

	for i := 0; i < n/2; i++ {
		if str[i] != str[n-i-1] {
			return false
		}
	}

	return true
}

func main() {
	line, _ := bufio.NewReader(os.Stdin).ReadString('\n')
	if isPalindrome(line[:len(line)-1]) { // Обрезаем \n в конце строки
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
