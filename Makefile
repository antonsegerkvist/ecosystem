CXX   ?= g++
MKDIR ?= mkdir -p

EXEC     ?= a.out
CXXFLAGS ?= -I /usr/local/Cellar
LIBS     ?= /usr/local/lib -lSDL2

BUILD_DIR ?= build
SRC_DIR   ?= source

SRCS := $(shell find $(SRC_DIR) -name '*.cpp' | sort -k 1nr | cut -f2-)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

.PHONY: all
all: $(OBJS)
	echo $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC) $(CXXFLAGS) -L $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(EXEC)
	rm -f $(OBJS)