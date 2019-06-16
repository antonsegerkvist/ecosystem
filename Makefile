CXX   ?= g++
MKDIR ?= mkdir -p

EXEC     ?= a.out
CXXFLAGS ?= -I /usr/local/Cellar/sdl2/2.0.8/include/SDL2 \
            -I /usr/local/Cellar/sdl2_ttf/2.0.14/include/SDL2
LIBS     ?= -L /usr/local/Cellar/sdl2/2.0.8/lib \
            -L /usr/local/Cellar/sdl2_ttf/2.0.14/lib \
						-lSDL2 -lSDL2_ttf

BUILD_DIR ?= build
SRC_DIR   ?= source

SRCS := $(shell find $(SRC_DIR) -name '*.cpp' | sort -k 1nr | cut -f2-)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

.PHONY: all
all: $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(CXXFLAGS) $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXEC)
	rm -f $(OBJS)