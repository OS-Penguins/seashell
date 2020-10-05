CC=gcc
CFLAGS=-Wall -Wextra

.PHONY = all clean

SRCS := $(wildcard src/*.c)
OBJS := $(SRCS:%.c=%.o)

OUTPUT=seashell

all: ${OBJS}
	${CC} ${CFLAGS} $^ -o ${OUTPUT}

%.o: %.c
	${CC} -c -o $@ ${CFLAGS} $^

clean:
	rm -rvf ${OBJS} ${OUTPUT}
