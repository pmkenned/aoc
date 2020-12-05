.PHONY: all clean

SHELL := /bin/bash

all: part1.exe

%.exe: %.d
	source /home/paul/dlang/dmd-2.094.2/activate && dmd -of=$@ $<

run: all
	./part1.exe

clean:
	rm -f *.exe *.o
