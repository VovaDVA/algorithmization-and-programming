package main

import (
	"fmt"
)

func main() {
	var a, b, c string
	fmt.Scan(&a, &b, &c)
	fmt.Print(answer(a, b, c))
}

func answer(a, b, c string) string {
	if a == "Нет" && b == "Нет" && c == "Нет" {
		return "Кот"
	} else if a == "Нет" && b == "Нет" && c == "Да" {
		return "Жираф"
	} else if a == "Нет" && b == "Да" && c == "Нет" {
		return "Курица"
	} else if a == "Нет" && b == "Да" && c == "Да" {
		return "Страус"
	} else if a == "Да" && b == "Нет" && c == "Нет" {
		return "Дельфин"
	} else if a == "Да" && b == "Нет" && c == "Да" {
		return "Плезиозавры"
	} else if a == "Да" && b == "Да" && c == "Нет" {
		return "Пингвин"
	} else {
		return "Утка"
	}
}
