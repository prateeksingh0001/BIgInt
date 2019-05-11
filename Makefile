CC = g++

BUILD_DIR := bin

BIGINT_PROGRAM := test_bigint
MERGESORT_PROGRAM := test_merge
QUICKSORT_PROGRAM := test_quicksort
GRAPH_PROGRAM := test_graph

CPPFLAGS = -g -Wall


all: build_dir $(BIGINT_PROGRAM) $(MERGESORT_PROGRAM) $(QUICKSORT_PROGRAM) $(GRAPH_PROGRAM)

build_dir:
	mkdir -p bin/

$(MERGESORT_PROGRAM):
	$(CC) tests/test_mergesort.cpp -o ./bin/$(MERGESORT_PROGRAM)

$(BIGINT_PROGRAM): bigint_exception.o bigint.o test_bigint.o
	$(CC) bigint.o test_bigint.o -o ./bin/$(BIGINT_PROGRAM) 

$(QUICKSORT_PROGRAM): 
	$(CC) tests/test_quicksort.cpp -o ./bin/$(QUICKSORT_PROGRAM)

$(GRAPH_PROGRAM): graph.o test_graph.o 
	$(CC) graph.o test_graph.o -o ./bin/$(GRAPH_PROGRAM)

test_merge.o:
	$(CC) -c $(CPPFLAGS) test_mergesort.cpp -std=c++11

bigint_exception.o:
	$(CC) -c $(CPPFLAGS) src/bigint_exception.h -std=c++11

bigint.o: 
	$(CC) -c $(CPPFLAGS) src/bigint.cpp -std=c++11

test_bigint.o: 
	$(CC) -c $(CPPFLAGS) src/test_bigint.cpp -std=c++11

graph.o:
	$(CC) -c $(CPPFLAGS) src/graph.cpp -std=c++11

test_graph.o:
	$(CC) -c $(CPPFLAGS) tests/test_graph.cpp -std=c++11
 
clean:
	rm  -rf *o ./bin/
