package main

import (
	"encoding/json"
	"fmt"
	"os"
)

type project struct {
	Project_id int    `json:"project_id"`
	Tasks      []Task `json:"tasks"`
}
type Task struct {
	User_id   int    `json:"user_id"`
	Id        int    `json:"id"`
	Title     string `json:"title"`
	Completed bool   `json:"completed"`
}

func main() {
	var n int
	fmt.Scan(&n)
	bytes, err := os.ReadFile("data.json")

	if err != nil {
		panic(err)
	}

	var projects []project
	err1 := json.Unmarshal(bytes, &projects)

	if err1 != nil {
		panic(err1)
	}

	answ := 0
	for i := range projects {
		for j := range projects[i].Tasks {
			if projects[i].Tasks[j].User_id == n && projects[i].Tasks[j].Completed == true {
				answ++
			}
		}
	}

	fmt.Print(answ)

}
