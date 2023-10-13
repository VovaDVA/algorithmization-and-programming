package main

import "fmt"

func main() {
    var n int;
    fmt.Scan(&n)
    nums := make(map[int]bool)
    
    for i := 0; i < n; i++ {
        var num int
        fmt.Scan(&num)
        if _, ok := nums[num]; ok {
            delete(nums, num)
        } else {
            nums[num] = true
        }
    }
    
    for num := range nums {
        fmt.Print(num)
        break
    }
    
}
