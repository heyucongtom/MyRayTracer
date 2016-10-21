IDIR = /opt/local/include
CC=g++
CFLAGS=-I $(IDIR) -lpng
STD=-std=c++0x

png_out: 
	$(CC) -c ./png_out.hpp $(CFLAGS) 

test_out_img:
	$(CC) -o test_img_1 ./tests/test_output_img.cpp $(CFLAGS) 

test_vec:
	$(CC) -o test_vector ./tests/test_vectors.cpp $(CFLAGS)