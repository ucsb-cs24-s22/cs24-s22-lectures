# Makefile
# -g includes debugging info
all: linkedlist
	./linkedlist
	
linkedlist: linkedlist.cpp linkedlist.h
	g++ -std=c++11 -O0 -g linkedlist.cpp -o linkedlist

clean:
	rm linkedlist