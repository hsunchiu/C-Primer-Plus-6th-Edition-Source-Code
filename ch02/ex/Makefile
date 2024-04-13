.DEFAULT_GOAL := all

CC ?= cc
CFLAGS = -Wall -Werror -Wextra

all: name name_address days jolly br_ic toes smile one_three

name: 1.c
	$(CC) $(CFLAGS) -o $@ $<

name_address: 2.c
	$(CC) $(CFLAGS) -o $@ $<

days: 3.c
	$(CC) $(CFLAGS) -o $@ $<

jolly: 4.c
	$(CC) $(CFLAGS) -o $@ $<

br_ic: 5.c
	$(CC) $(CFLAGS) -o $@ $<

toes: 6.c
	$(CC) $(CFLAGS) -o $@ $<

smile: 7.c
	$(CC) $(CFLAGS) -o $@ $<

one_three: 8.c
	$(CC) $(CFLAGS) -o $@ $<


.PHONY:
clean: 
	-rm name name_address days jolly br_ic toes smile one_three
