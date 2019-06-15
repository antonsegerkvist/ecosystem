CXX     ?= g++
EXEC    ?= a.out
INCLUDE ?= /usr/local/Cellar
LIBS    ?= /usr/local/lib -lSDL2

all: ecosystem

.PHONY: ecosystem
ecosystem:
	$(CXX) source/main.cpp -o $(EXEC) -I $(INCLUDE) -L $(LIBS)