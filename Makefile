CC=/usr/bin/clang
SRC=PH_Pascal_Triangle_2025/pascal_pyramid.c
BIN=build/pascal_pyramid

CFLAGS_BASE=-std=c17 -Wall -Wextra -g
CFLAGS_STRICT=$(CFLAGS_BASE) -Wpedantic -Wshadow -Wconversion -fsanitize=address,undefined -fno-omit-frame-pointer

all: $(BIN)
strict: | build
	$(CC) $(CFLAGS_STRICT) $(SRC) -o $(BIN)

$(BIN): | build
	$(CC) $(CFLAGS_BASE) $(SRC) -o $(BIN)

build:
	mkdir -p build

run: all
	./$(BIN)

test: all
	./$(BIN) 5 > out.txt
	@diff -u expected.txt out.txt && echo "OK" || (echo "FAILED"; exit 1)

clean:
	rm -rf build out.txt

.PHONY: all run clean test strict
