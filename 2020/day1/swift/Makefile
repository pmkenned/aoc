.PHONY: all part1 part2 run perf clean

all: part1

part1: part1.exe
part2: part2.exe

%.exe: %.swift
	swiftc -o $@ $<

run: all
	./part1.exe

perf: all
	./do_n.sh ./part1.exe 10

clean:
	rm -f *.exe
