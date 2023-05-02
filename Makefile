CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror -pedantic

tictactoe: tictactoe.o
	$(CXX) $(CXXFLAGS) -o tictactoe tictactoe.o

tictactoe.o: tictactoe.cpp
	$(CXX) $(CXXFLAGS) -c tictactoe.cpp

clean:
	rm -f tictactoe tictactoe.o
