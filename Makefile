.PHONY: build
FLAGS = -Wall -g -Wextra
COMPILER = gcc

build:
	$(COMPILER) $(FLAGS) src/*.c -o tema3 -Iinclude

clean:
	rm -f tema3	