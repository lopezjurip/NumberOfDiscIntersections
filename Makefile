default: all

build:
	gcc -Wall -lm -std=c99 main.c -o ./main

run:
	./main

clean:
	rm ./main

all:
	make build
	make run
	make clean
