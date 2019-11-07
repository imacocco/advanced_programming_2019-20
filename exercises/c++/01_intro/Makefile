CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++11

SRC = 01_compiler.cc            \
      02_uniq_emulator.cc           \
      03_get_num.cc                \
      04_UoM.cc   \
#      05_functions.cc            \
#      06_watch_out.cc 

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
