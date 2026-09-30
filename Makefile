CC = cc
CFLAGS = -std=c99 -Wall -Wextra
BINARY = example

.PHONY: all
all: $(BINARY)

$(BINARY): example.o str_view.o str_builder.o
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c %.h
	$(CC) $(CFLAGS) -c -o $@ $<

.PHONY: clean
clean:
	rm -rf $(BINARY) *.o
