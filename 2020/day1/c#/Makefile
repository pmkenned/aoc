.PHONY: all part1 run perf clean

all: part1

part1: part1.exe

%.exe: %.cs
	mono-csc $<

run: all
	./part1.exe

perf: all
	./do_n.sh ./part1.exe 10

clean:
	rm -f *.exe
