CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++11 -Wno-unused-parameter

SRC = 01_transpose.cc            \
      02_argv.cc           \
      03_mean_med.cc                \
      04_repetitions.cc   \
      05_women.cc            \

EXE = $(SRC:.cc=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cc .x

all: $(EXE)

.PHONY: all

%.x: %.cc 
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean
