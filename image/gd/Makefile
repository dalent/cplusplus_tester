TARGET=a.out
#SRC=$(shell ls *.cpp)
SRC=gd_resize.cpp
OBJ=$(patsubst %.cpp,%.o,$(SRC))

CC=g++
CFLAGS=-I/usr/local/include/ -L /usr/local/lib -lgd -lpng -lz -ljpeg -lfreetype -lm -g -Bstatic
all:$(TARGET)

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS)  -o $@  $< 
%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

