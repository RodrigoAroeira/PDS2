CXX = g++
STD = c++11

SRC_DIR = src
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
HEADER_DIR = include
OBJ_DIR = build
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC_FILES))

OUT = vpl_execution

CXXFLAGS = -I$(HEADER_DIR) -O3 -std=$(STD)

build: $(OBJ_FILES)
	$(CXX) $(OBJ_FILES) $(CXXFLAGS) -o $(OUT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: build verbose
