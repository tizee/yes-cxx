.PHONY: clean, mrproper
CC = g++
CFLAGS = -g -O2 -Wall -std=c++11

all: yes

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

yes: yes.o
	$(CC) $(CFLAGS) -o $@ $+

clean:
	rm -f *.o core.*

mrproper: clean
	rm -f yes
