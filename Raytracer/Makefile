IDIR = /opt/local/include
CC=g++
CFLAGS=-I $(IDIR) -lpng -O3
STD=-std=c++0x

boost_ex1: 
	$(CC) -o boost_ex1 $(CFLAGS) boost_trail.cpp $(STD)

png_out: 
	$(CC) -c ./png_out.hpp $(CFLAGS) 

test_out_img:
	$(CC) -o test_img_1 ./tests/test_output_img.cpp $(CFLAGS) 