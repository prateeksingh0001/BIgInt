CC = g++

BUILD_DIR := bin

PROGRAM_NAME := test_bigint

CPPFLAGS = -g -Wall


all: build_dir $(PROGRAM_NAME) 

build_dir:
	mkdir -p bin/

$(PROGRAM_NAME): bigint.o test_bigint.o 
	$(CC) bigint.o test_bigint.o -o ./bin/$(PROGRAM_NAME) 

bigint.o: 
	$(CC) -c $(CPPFLAGS) src/bigint.cpp -std=c++11

test_bigint.o: 
	$(CC) -c $(CPPFLAGS) src/test_bigint.cpp -std=c++11

clean:
	rm  -rf *o ./bin/