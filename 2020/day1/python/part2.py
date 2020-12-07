#!/usr/bin/env python3

if __name__ == "__main__":

    with open("../input.txt", "r") as fh:
        lines = fh.readlines()
    numbers = [int(line, 10) for line in lines]

    for i, number in enumerate(numbers):
        for j, number2 in enumerate(numbers[i+1:]):
            for k, number3 in enumerate(numbers[i+1+j+1:]):
                if number + number2 + number3 == 2020:
                    print(number*number2*number3)
                    break
