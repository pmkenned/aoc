package main

import (
    "fmt"
    "io/ioutil"
    "strings"
    "strconv"
)

func readInput() []int {
    dat, err := ioutil.ReadFile("../input.txt")
    if err != nil {
        panic(err)
    }
    dat_strs := strings.Split(string(dat), "\n")

    rv := make([]int, 0)

    for _, s := range dat_strs {
        x, err := strconv.Atoi(s)
        if err == nil {
            rv = append(rv, x)
        }
    }

    return rv
}

func main() {
    numbers := readInput()

    for i, n := range numbers {
        for j, m := range numbers[i+1:] {
            for _, o := range numbers[j+1:] {
                if n + m + o == 2020 {
                    fmt.Println(n * m * o)
                    break
                }
            }
        }
    }
}
