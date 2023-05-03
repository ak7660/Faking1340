CXXFLAGS = -std=c++11

maze_game: main.o maze.o minigame.o
	g++ $(CXXFLAGS) main.o maze.o minigame.o -o maze_game

main.o: main.cpp
	g++ $(CXXFLAGS) -c main.cpp

maze.o: maze.cpp maze.h
	g++ $(CXXFLAGS) -c maze.cpp

minigame.o: minigame.cpp minigame.h
	g++ $(CXXFLAGS) -c minigame.cpp

clean:
	rm -f *.o maze_game map maze.txt pospos.txt

run: maze_game map
	./map > maze.txt 2>pospos.txt && ./maze_game

all: map

map: map.cpp
	g++ -pedantic-errors -std=c++11 -o map map.cpp

generate: map
	./map > maze.txt 2> pospos.txt


