CC=g++
DEV=-Wall -g -std=c++14
OPT=-O3 -std=c++14

.PHONY: all
all: AVLCommands.exe

BST.o: BST.cpp BST.h
	$(CC) $(DEV) -c BST.cpp

AVL.o: AVL.cpp AVL.h BST.o
	$(CC) $(DEV) -c AVL.cpp

AVLCommands.exe: AVLCommands.cxx AVL.o json.hpp
	$(CC) $(DEV) AVLCommands.cxx AVL.o -o AVLCommands.exe

# Build
.PHONY: clean
clean:
	rm -f *.o
	rm -f *.exe
	rm -rf *dSYM

.PHONY: update
update:
	make clean
	make all
