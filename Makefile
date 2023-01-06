all: main

main:
	g++ -g -Wall main.cpp src/Graph.cpp src/pthinness.cpp -o main

clean:
	rm main
