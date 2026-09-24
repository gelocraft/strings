CC = cc
CFLAGS = -std=c99 -Wall -Wextra
BINARY = example

.PHONY: all
all: $(BINARY)

$(BINARY): example.o str_view.o
	$(CC) $(CFLAGS) -o $@ $^

str_view.o: str_view.c str_view.h
	$(CC) $(CFLAGS) -c -o $@ $<

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^


.PHONY: clean
clean:
	rm -rf $(BINARY) *.o
