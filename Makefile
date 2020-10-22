CC=g++
CFLAGS=-Wall -Wextra -std=c++17 -O2

.PHONY = all clean

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:src/%.cpp=build/%.o)

OUTPUT=seashell

all: ${OBJS}
	${CC} ${CFLAGS} $^ -o ${OUTPUT}

build/%.o: src/%.cpp
	mkdir -p build
	${CC} ${CFLAGS} -c $^ -o $@

clean:
	rm -rvf ${OBJS} ${OUTPUT} build

format:
	clang-format -i -style=file ${SRCS}
