CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-g
LDFLAGS=-g
LDLIBS=

SRCS=tictactoe.cpp minimax-lib/minimax.h minimax-lib/game.h
OBJS=$(subst .cpp,.o,$(SRCS))

all: tictactoe

tictactoe: $(OBJS)
	$(CXX) $(LDFLAGS) -o tictactoe $(OBJS) $(LDLIBS)

tictactoe.o: tictactoe.cpp

clean:
	$(RM) $(OBJS)
