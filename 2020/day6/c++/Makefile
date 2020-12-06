CXX=g++
CXXFLAGS=-Wall -Wextra -pedantic -std=c++11 -Weffc++ -O2

.PHONY: all part1 part2 run perf clean

all: part1 part2
part1: part1.exe
part2: part2.exe

%.exe: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run: all
	./part1.exe
	./part2.exe

perf: all
	./do_n.sh ./part1.exe 10
	./do_n.sh ./part2.exe 10

clean:
	rm -f *.exe *.o
