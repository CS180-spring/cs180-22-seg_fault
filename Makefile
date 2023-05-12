OBJS	= main.o document.o userAccounts.o userInterface.o collection.o
SOURCE	= main.cpp document.cpp userAccounts.cpp userInterface.cpp collection.cpp
HEADER	= document.hpp userAccounts.hpp userInterface.hpp collection.hpp
OUT	= datastore
LFLAGS	 = -lstdc++ -std=c++11 -Wall -O2

all: datastore

datastore: $(OBJS)
	$(CC) -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CC) -c -o $@ $< $(LFLAGS)

clean:
	rm -f $(OBJS) $(OUT)