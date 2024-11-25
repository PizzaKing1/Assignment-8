GCC = gcc -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic
SRCS = a6.c
OBJS = $(SRCS:%.c=%.o)
TARGET = a6
default: $(OBJS)
	$(GCC) $(OBJS) -o $(TARGET)

test0: a6
	./a6 points.txt

test1: a6
	./a6 p0.txt
	
clean:
	rm a6; rm *.o
	
#gcc -O3 -std=c99 -Wall -Wshadow -Wvla -pedantic