GCC = gcc -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic
SRCS = a8.c
OBJS = $(SRCS:%.c=%.o)
TARGET = a8
default: $(OBJS)
	$(GCC) $(OBJS) -o $(TARGET)

test0: a8
	./a8 points.txt

test1: a8
	./a8 p0.txt
	
clean:
	rm a8; rm *.o
	
#gcc -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic