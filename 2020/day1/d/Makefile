.PHONY: all clean

# Need to: source ~/dlang/dmd-2.094.2/activate

all: part1.exe

part1.exe: part1.d
	dmd -of=part1.exe part1.d

clean:
	rm -f *.exe *.o
