package main

import (
	"fmt"
)

const rows int = 9
const cols int = 9

func isValidSudoku(bord [9][9]int) bool {
	for i := 0; i < len(bord); i++ {
		for j := 0; j < len(bord[0]); j++ {
			if !isValidRow(bord, i, j) || !isValidCol(bord, i, j) || !isValidSquare(bord, i, j) {
				return false
			}
		}
	}

	return true
}

func isValidRow(bord [9][9]int, y int, x int) bool {
	for j := 0; j < x; j++ {
		if bord[y][x] == bord[y][j] {
			return false
		}
	}
	for j := x + 1; j < len(bord[0]); j++ {
		if bord[y][x] == bord[y][j] {
			return false
		}
	}

	return true
}

func isValidCol(bord [9][9]int, y int, x int) bool {
	for i := 0; i < y; i++ {
		if bord[y][x] == bord[i][x] {
			return false
		}
	}
	for i := y + 1; i < len(bord); i++ {
		if bord[y][x] == bord[i][x] {
			return false
		}
	}

	return true
}

func isValidSquare(bord [9][9]int, y int, x int) bool {
	divX := (x + 1) % 3
	divY := (y + 1) % 3

	points := [8]int{}

	if divX == 1 && divY == 1 {
		points = [8]int{bord[y][x+1], bord[y][x+2], bord[y+1][x], bord[y+1][x+1], bord[y+1][x+2], bord[y+2][x], bord[y+2][x+1], bord[y+2][x+2]}
	} else if divX == 2 && divY == 1 {
		points = [8]int{bord[y][x-1], bord[y][x+1], bord[y+1][x-1], bord[y+1][x], bord[y][x+1], bord[y+2][x-1], bord[y+2][x], bord[y+2][x+1]}
	} else if divX == 3 && divY == 1 {
		points = [8]int{bord[y][x-2], bord[y][x-1], bord[y+1][x-2], bord[y+1][x-1], bord[y+1][x], bord[y+2][x-2], bord[y+2][x-1], bord[y+2][x]}
	} else if divX == 1 && divY == 2 {
		points = [8]int{bord[y-1][x], bord[y-1][x+1], bord[y-1][x+2], bord[y][x+1], bord[y][x+2], bord[y+1][x], bord[y+1][x+1], bord[y+1][x+2]}
	} else if divX == 2 && divY == 2 {
		points = [8]int{bord[y-1][x-1], bord[y-1][x], bord[y-1][x+1], bord[y][x-1], bord[y][x+1], bord[y+1][x-1], bord[y+1][x], bord[y+1][x+1]}
	} else if divX == 3 && divY == 2 {
		points = [8]int{bord[y-1][x-2], bord[y-1][x-1], bord[y-1][x], bord[y][x-2], bord[y][x-1], bord[y+1][x-2], bord[y+1][x-1], bord[y+1][x]}
	} else if divX == 1 && divY == 3 {
		points = [8]int{bord[y-2][x], bord[y-2][x+1], bord[y-2][x+2], bord[y-1][x], bord[y-1][x+1], bord[y-1][x+2], bord[y][x+1], bord[y][x+2]}
	} else if divX == 2 && divY == 3 {
		points = [8]int{bord[y-2][x-1], bord[y-2][x], bord[y-2][x+1], bord[y-1][x-1], bord[y-1][x], bord[y-1][x+1], bord[y][x-1], bord[y][x+1]}
	} else if divX == 3 && divY == 3 {
		points = [8]int{bord[y-2][x-2], bord[y-2][x-1], bord[y-2][x], bord[y-1][x-2], bord[y-1][x-1], bord[y-1][x], bord[y][x-2], bord[y][x-1]}
	}

	return !contains(points, bord[y][x])
}

func contains(s [8]int, e int) bool {
	for _, a := range s {
		if a == e {
			return true
		}
	}
	return false
}

func main() {
	var bord [rows][cols]int

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			fmt.Scanf("%c", &bord[row][col]) // Считываем один символ
			bord[row][col] -= '0'            // Чтобы из ASCII кода символа получить цифру
		}
		fmt.Scanf("\n")
	}

	if isValidSudoku(bord) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
