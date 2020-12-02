.PHONY: all clean

all: part1.exe

%.o: %.s
	as -o $@ $<

%.exe: %.o
	ld -o $@ $^

clean:
	rm -f *.exe *.o
