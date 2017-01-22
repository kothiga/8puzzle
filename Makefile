

CC= g++
CFLAGS = -g -ldl -std=c++11 -lpthread -lX11
objects = 8puzzle.o Board_Tile.o Sliding_Solver.o

8puzzle : $(objects)
	$(CC) -o $@  $(objects)

%.o : %.cc
	$(CC) $(CFLAGS) -c $^

.PHONY : clean

clean :
	rm -rf *.o *~ *.d 
clean-all:
	rm -rf *.o *~ *.d 8puzzle

