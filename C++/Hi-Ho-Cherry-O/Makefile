.phony: clean all

OBJS = cherryGame

CXXFLAGS = -O3 -g -Wall -Wpedantic -Wextra -Wshadow -Wunused -Wunused-parameter  -Wunused -Wuninitialized -Wshadow -Werror -Wmisleading-indentation -Wconversion  -std=c++17 

all: ${OBJS}

SpinT.o: SpinT.h PlayerT.h
PlayerT.o: PlayerT.h

cherryGame: PlayerT.o SpinT.o

clean:
	rm -f ${OBJS} *.o