.PHONY: all run perf clean

MAKEFLAGS += --no-print-directory 


all:
	make -C c
	make -C c++
	make -C haskell
	make -C rust
	make -C ocaml
	make -C scala
	make -C java
	make -C go
	make -C "c#"
	make -C asm
	make -C d
	make -C algol
	make -C basic
	make -C forth
	make -C fortran

#run: MAKEFLAGS += --silent
run:
	@echo "\n==== C =========="
	@make -C c run
	@echo "\n==== C++ ========"
	@make -C c++ run
	@echo "\n==== Go ========="
	@make -C go run
	@echo "\n==== Haskell ===="
	@make -C haskell run
	@echo "\n==== Rust ======="
	@make -C rust run
	@echo "\n==== OCaml ======"
	@make -C ocaml run
	@echo "\n==== Scala ======"
	@make -C scala run
	@echo "\n==== Java ======="
	@make -C java run
	@echo "\n==== Awk ========"
	@cd awk && ./part1.awk ../input.txt
	@echo "\n==== Python ====="
	@cd python && ./part1.py && ./part2.py
	@echo "\n==== JavaScript ="
	@cd javascript && node ./part1.js && node ./part2.js
	@echo "\n==== Perl ======="
	@cd perl && ./part1.pl && ./part2.pl
	@echo "\n==== PHP ========"
	@cd php && ./part1.php && ./part2.php
	@echo "\n==== Ruby ======="
	@cd ruby && ./part1.rb
	@echo "\n==== Elixir ====="
	@cd elixir && ./part1.exs
	@echo "\n==== Clojure ===="
	@cd clojure && ./part1.clj
	@echo "\n==== Lua ========"
	@cd lua && ./part1.lua
	@echo "\n==== R =========="
	@cd r && ./part1.r
	@echo "\n==== Julia ======"
	@cd julia && ./part1.jl
	@echo "\n==== C# ========="
	@make -C "c#" run
	@echo "\n==== asm ========"
	@make -C asm run
	@echo "\n==== D =========="
	@make -C d run
	@echo "\n==== Algol ======"
	@make -C algol run
	@echo "\n==== Basic ======"
	@make -C basic run
	@echo "\n==== Forth ======"
	@make -C forth run
	@echo "\n==== Fortran ===="
	@make -C fortran run

perf: all
	@echo "\n==== C =========="
	@make -C c perf
	@echo "\n==== C++ ========"
	@make -C c++ perf
	@echo "\n==== Haskell ===="
	@make -C haskell perf
	@echo "\n==== Rust ======="
	@make -C rust perf
	@echo "\n==== OCaml ======"
	@make -C ocaml perf
	@echo "\n==== Python ====="
	@cd python && ./do_n.sh ./part1.py 10
	@echo "\n==== Scala ======"
	@make -C scala perf
	@echo "\n==== Java ======="
	@make -C java perf
	@echo "\n==== Go ========="
	@make -C go perf

clean:
	make -C c clean
	make -C c++ clean
	make -C haskell clean
	make -C rust clean
	make -C ocaml clean
	make -C scala clean
	make -C java clean
	make -C go clean
	make -C "c#" clean
	make -C asm clean
	make -C d clean
