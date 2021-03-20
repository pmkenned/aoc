.PHONY: all clean

SHELL := /bin/bash

all: part1.exe

%.exe: %.d
	source /home/paul/bin/dlang/dmd-2.095.1/activate && dmd -of=$@ $<

run: all
	./part1.exe

clean:
	rm -f *.exe *.o
