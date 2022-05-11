# Makefile
# -g includes debugging info
all: linkedlist
	./linkedlist
	
linkedlist: linkedlist.cpp linkedlist.h test_linkedlist.cpp
	g++ -std=c++11 -O0 -g test_linkedlist.cpp -o linkedlist

clean:
	rm linkedlist