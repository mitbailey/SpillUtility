CXX = g++
CC = gcc
CPPOBJS = src/spill.o
COBJS =
EDCXXFLAGS = -I ./ -I ./include/ -Wall -pthread -std=gnu++17 $(CXXFLAGS)
EDCFLAGS = $(CFLAGS)
EDLDFLAGS := -lstdc++fs -static-libgcc -static-libstdc++ $(LDFLAGS)
TARGET = spill.out

all: $(COBJS) $(CPPOBJS)
	$(CXX) $(EDCXXFLAGS) $(COBJS) $(CPPOBJS) -o $(TARGET) $(EDLDFLAGS)
	# ./$(TARGET)

%.o: %.cpp
	$(CXX) $(EDCXXFLAGS) -o $@ -c $<

%.o: %.c
	$(CC) $(EDCFLAGS) -o $@ -c $<

.PHONY: clean

clean:
	$(RM) *.out
	$(RM) *.o
	$(RM) src/*.o

.PHONY: spotless