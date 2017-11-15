all: wzo brut gen

wzo: wzo.cpp
	g++ -g $^ -std=c++11 -o $@

brut: brut.cpp
	g++ -O2 $^ -std=c++11 -o $@

gen: gen.cpp
	g++ -O2 $^ -std=c++11 -o $@
