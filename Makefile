
CPP      = g++
CPPFLAGS = -c -g -Wall -pedantic -std=c++11

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -o $@ $<

SRC = edge.cpp graph.cpp mst.cpp union_find.cpp 
H   = edge.hpp graph.hpp mst.hpp union_find.hpp

all: dependencies foo

dependencies: $(SRC) $(H)
	 rm -f dependencies
	 $(CC) $(CPPFLAGS) -MM $(SRC) >> dependencies

include dependencies

foo: main.o edge.o graph.o mst.o union_find.o 
	g++ -o foo -g -std=c++11 main.o edge.o graph.o mst.o union_find.o

clean: 
	rm dependencies main.o edge.o graph.o mst.o union_find.o
