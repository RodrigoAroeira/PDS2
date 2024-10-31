CXX = g++

STD = c++11

SRC_DIR = .
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

HEADER_DIR = headers
INCLUDE_DIR = includes/usr/include

OUT = TADs.exe

CXXFLAGS = -I$(HEADER_DIR) -O3 -std=$(STD)

build:
	$(CXX) $(SRC_FILES) $(CPPFLAGS) -o $(OUT)

run:
	./$(OUT)

clean:
	rm -f $(OUT)

.PHONY: build run clean
