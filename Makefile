SOURCE	= $(shell find . -name "*.cpp")
OBJS	= $(SOURCE:%.cpp=%.o)
CC		= g++

all: runelection

runelection: $(OBJS)
	$(CC) $(OBJS) -o $@

clean:
	rm -f *.o Files/*.o Functions/*.o Structures/*.o