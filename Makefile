CC=g++
CFLAGS=-Wall -Wextra -std=c++17 -O2

.PHONY = all clean

SRCS := $(wildcard src/*.cpp)
OBJS := $(SRCS:%.cpp=%.o)

OUTPUT=seashell

all: ${OBJS}
	${CC} ${CFLAGS} $^ -o ${OUTPUT}

%.o: %.cpp
	${CC} ${CFLAGS} -c $^ -o $@

clean:
	rm -rvf ${OBJS} ${OUTPUT}

format:
	clang-format -i -style=file ${SRCS}
