CC = gcc
MAIN = main.c
HEADERS = mysorts.h
SRCS =
BINS = ${MAIN:.c=.exe}
CFLAGS = -fopenmp -O3 -Wall -Wextra

all: ${BINS}

%.exe: ${MAIN} ${SRCS}
	${CC} ${CFLAGS} ${SRCS} ${MAIN} -o ${BINS}

%.c: ${HEADERS}

run: ${BINS}
	@.\${BINS}