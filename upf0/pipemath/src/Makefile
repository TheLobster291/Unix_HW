LIBS = -lm
INC = -I ../inc
CFLAGS = -Wall --std=gnu18
CC = gcc
SRC = $(shell /bin/ls -1 *.c 2>/dev/null)
BIN = $(SRC:.c=)
PROJ = pipemath
USERPWD = $(USERPATH)
BINPATH = ../bin
all: clean $(SRC) $(BIN)

debug: CFLAGS += -DDEBUG -g
debug: DEBUG = debug
debug: clean $(SRC) $(BIN) 

.c:
ifneq ($(MAKECMDGOALS),debug)
	@printf "[\033[0;33mCC\033[0m]   %-20s ... " "$<"
	@$(CC) $(CFLAGS) $(INC) -o $(BINPATH)/$@ $< $(LIBS) 2>> errors && echo "\033[0;32mOK\033[0m" || echo "\033[0;31mFAIL\033[0m"
else
	$(CC)  $(CFLAGS) $(INC) -o $(BINPATH)/$@ $< $(LIBS)
endif

clean:
	@/bin/rm -vf .*.sw[op] *.save* *~ core errors
