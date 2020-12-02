.PHONY: all part1 run perf clean

all: part1

part1: Part1.class

%.class: %.scala
	scalac $<

run: all
	scala Part1

perf: all
	./do_n.sh Part1 10

clean:
	rm -f *.class
