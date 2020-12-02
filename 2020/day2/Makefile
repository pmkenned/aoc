.PHONY: all run perf clean

MAKEFLAGS += --no-print-directory 

all:
	-make -C c
	-make -C c++
	-make -C haskell
	-make -C rust
	-make -C ocaml
	-make -C scala
	-make -C java
	-make -C go

#run: MAKEFLAGS += --silent
run:
	@echo "\n==== C =========="
	@-make -C c run
	@echo "\n==== C++ ========"
	@-make -C c++ run
	@echo "\n==== Haskell ===="
	@-make -C haskell run
	@echo "\n==== Rust ======="
	@-make -C rust run
	@echo "\n==== OCaml ======"
	@-make -C ocaml run
	@echo "\n==== Python ====="
	@-cd python && ./part1.py
	@echo "\n==== Scala ======"
	@-make -C scala run
	@echo "\n==== Java ======="
	@-make -C java run
	@echo "\n==== Go ========="
	@-make -C go run

perf: all
	@echo "\n==== C =========="
	@-make -C c perf
	@echo "\n==== C++ ========"
	@-make -C c++ perf
	@echo "\n==== Haskell ===="
	@-make -C haskell perf
	@echo "\n==== Rust ======="
	@-make -C rust perf
	@echo "\n==== OCaml ======"
	@-make -C ocaml perf
	@echo "\n==== Python ====="
	@-cd python && ./do_n.sh ./part1.py 10
	@echo "\n==== Scala ======"
	@-make -C scala perf
	@echo "\n==== Java ======="
	@-make -C java perf
	@echo "\n==== Go ========="
	@-make -C go perf

clean:
	-make -C c clean
	-make -C c++ clean
	-make -C haskell clean
	-make -C rust clean
	-make -C ocaml clean
	-make -C scala clean
	-make -C java clean
	-make -C go clean
