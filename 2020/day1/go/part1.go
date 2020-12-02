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

    for _, num := range numbers {
        sought := 2020 - num
        for _, v := range numbers {
            if v == sought {
                fmt.Println(v * num)
                break
            }
        }
    }
}
