.PHONY: all part1 part2 run perf clean

all: part1 part2

part1: Part1.class
part2: Part2.class

%.class: %.java
	javac $<

run: all
	java Part1
	java Part2

perf: all
	./do_n.sh Part1 10
	./do_n.sh Part2 10

clean:
	rm -f *.class
