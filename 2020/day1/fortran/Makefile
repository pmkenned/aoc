.PHONY: all part1 run clean

all: part1
part1: part1.exe

%.exe: %.f
	gfortran -o $@ $<

run: all
	./part1.exe

clean:
	rm -f *.exe
