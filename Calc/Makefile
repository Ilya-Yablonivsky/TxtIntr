.PHONY: all debug release clean
NAME = Calc
DEBUG = -g -Wall
RELEASE = -Wall -DNDEBUG
DB_EXEC = $(NAME)-dbg
RL_EXEC = $(NAME)
SOURCE = *.cpp
all: debug release
debug: $(DB_EXEC)
release: $(RL_EXEC)
clean:
	rm -f $(RL_EXEC) $(DB_EXEC)
$(DB_EXEC): $(SOURCE)
	g++ $(DEBUG) $(SOURCE) -o $(DB_EXEC)

$(RL_EXEC): $(SOURCE)
	g++ $(RELEASE) $(SOURCE) -o $(RL_EXEC)
