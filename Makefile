CC ?= clang
CFLAGS ?= -fsanitize=signed-integer-overflow -fsanitize=undefined -ggdb3 -O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wshadow
LDLIBS ?= -lm

crack: crack.c
	$(CC) $(CFLAGS) crack.c -o crack $(LDLIBS)

.PHONY: clean
clean:
	rm -f crack
