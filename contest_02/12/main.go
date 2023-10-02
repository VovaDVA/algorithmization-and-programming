package main

import (
	"fmt"
)

func fill(maze [][]int) {
	for i := 0; i < len(maze); i++ {
		for j := 0; j < len(maze[i]); j++ {
			if maze[i][j] >= 0 {
				maze[i][j] = bombCount(maze, i, j)
			}
		}
	}
}

func bombCount(maze [][]int, i int, j int) int {
	cnt := 0

	if i > 0 && j > 0 && maze[i-1][j-1] < 0 {
		cnt++
	}
	if i > 0 && maze[i-1][j] < 0 {
		cnt++
	}
	if i > 0 && j < len(maze[i])-1 && maze[i-1][j+1] < 0 {
		cnt++
	}
	if j > 0 && maze[i][j-1] < 0 {
		cnt++
	}
	if j < len(maze[i])-1 && maze[i][j+1] < 0 {
		cnt++
	}
	if i < len(maze)-1 && j > 0 && maze[i+1][j-1] < 0 {
		cnt++
	}
	if i < len(maze)-1 && maze[i+1][j] < 0 {
		cnt++
	}
	if i < len(maze)-1 && j < len(maze[i])-1 && maze[i+1][j+1] < 0 {
		cnt++
	}

	return cnt
}

func main() {
	var rows, cols int
	fmt.Scanf("%d %d\n", &rows, &cols)

	// Создаём срез и заполняем его данными о расположении мин
	maze := make([][]int, rows, rows)
	for i := range maze {
		maze[i] = make([]int, cols, cols)
		for j := range maze[i] {
			fmt.Scanf("%d", &maze[i][j])
		}
	}

	// Заполняем игровое поле подсказками
	fill(maze)

	// Выводим на экран
	for _, row := range maze {
		for _, cell := range row {
			fmt.Printf("%3d", cell)
		}
		fmt.Println()
	}
}
