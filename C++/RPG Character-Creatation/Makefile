CXXFLAGS = -g -O3 -Wpedantic -Wall -Wextra -Wmisleading-indentation -Wunused -Wuninitialized -Wshadow -Wconversion  -std=c++17

# Everything to make in this directory
OBJS = test

# Make everything
all: ${OBJS}

test: Entity.o

Entity.o: Entity.h

.PHONY: clean
clean:
	rm -f *.o ${OBJS} *~

