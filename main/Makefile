CC = gcc


CCWARNINGS = -Wall -W
CCOPT = -std=c11 -g

CFLAGS = $(CCWARNINGS) $(CCOPT)

MAIN_SOURCES := main.c box.c
MAIN_OBJECTS := $(MAIN_SOURCES:.c=.o)

MAIN_EXECUTABLE = cmd_int

EXECS = $(MAIN_EXECUTABLE)

.PHONY: all run-demo run test

all: $(EXECS) 

%.o: %.c box.h
	$(CC) $(CFLAGS) -c $< -o $@

$(MAIN_EXECUTABLE): $(MAIN_OBJECTS)
	$(CC) $(CFLAGS) $(MAIN_OBJECTS) -o $@

run: $(MAIN_EXECUTABLE)
	./$(MAIN_EXECUTABLE)

test: $(MAIN_EXECUTABLE)
	./test.sh

clean:
	rm -rf *.o *~  

clean-all: clean
	rm -rf $(EXECS) 


