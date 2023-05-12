# Makefile

# Dependencies
OBJS	= main.o document.o userAccounts.o userInterface.o collection.o
SOURCE	= main.cpp document.cpp userAccounts.cpp userInterface.cpp collection.cpp
HEADER	= document.hpp userAccounts.hpp userInterface.hpp collection.hpp

# Target executable
OUT	= datastore

# Compiler and flags
LFLAGS = -lstdc++ -std=c++11 -Wall -O2
CXX = g++

# Build and run
all: datastore

datastore: $(OBJS)
	$(CXX) -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CXX -c -o $@ $< $(LFLAGS)

# Remove objects
clean:
	rm -f $(OBJS) $(OUT)