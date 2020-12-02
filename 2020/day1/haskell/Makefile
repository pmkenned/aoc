.PHONY: all part1 run perf clean

all: part1

part1: part1.exe

%.exe: %.hs
	ghc -o $@ $<

run: all
	./part1.exe

perf: all
	./do_n.sh ./part1.exe 10

clean:
	rm -f *.o *.hi *.exe
