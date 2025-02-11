all: output

output: main.cc
	g++ -o output main.cc

clean:
	rm -f output