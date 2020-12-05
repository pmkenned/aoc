.PHONY: all clean

all: part1.exe

%.o: %.s
	as -o $@ $<

%.exe: %.o
	ld -o $@ $^

run: all
	./part1.exe

clean:
	rm -f *.exe *.o
