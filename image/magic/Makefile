TARGET=a.out
SRC=$(shell ls *.cpp)
OBJ=$(patsubst %.cpp,%.o,$(SRC))

CC=g++
CFLAGS=`Magick++-config --cxxflags --cppflags`
all:$(TARGET)

$(TARGET):$(OBJ)
	$(CC) $(CFLAGS) -o $@  $< `Magick++-config --ldflags --libs` 
%.o:%.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

