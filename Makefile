all: output

output: main.cc
	g++ -std=c++11 -o output main.cc

clean:
	rm -f output