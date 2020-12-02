#!/usr/bin/env python3

if __name__ == "__main__":

    with open("../input.txt", "r") as fh:
        lines = fh.readlines()
    numbers = [int(line, 10) for line in lines]

    for number in numbers:
        sought = 2020 - number
        if sought in numbers:
            print(sought * number)
            break
