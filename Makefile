CC = g++

BUILD_DIR := bin

PROGRAM_NAME := test_bigint

CPPFLAGS = -g -Wall


all: build_dir $(PROGRAM_NAME) 

build_dir:
	mkdir -p bin/

$(PROGRAM_NAME): bigint_exception.o bigint.o merge.o test_bigint.o test_merge.o  
	$(CC) bigint.o test_bigint.o -o ./bin/$(PROGRAM_NAME) 

test_merge: merge.o test_merge.o
	$(CC) merge.o test_bigint.o -o ./bin/test_merge

test_merge.o:
	$(CC) -c $(CPPFLAGS) test_mergesort.cpp -std=c++11

merge.o:
	$(CC) -c $(CPPFLAGS) src/merge.h -std=c++11

bigint_exception.o:
	$(CC) -c $(CPPFLAGS) src/bigint_exception.h -std=c++11

bigint.o: 
	$(CC) -c $(CPPFLAGS) src/bigint.cpp -std=c++11

test_bigint.o: 
	$(CC) -c $(CPPFLAGS) src/test_bigint.cpp -std=c++11

clean:
	rm  -rf *o ./bin/
