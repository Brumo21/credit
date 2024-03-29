CXX       := g++
CXX_FLAGS := -Wall -Wextra -O3 

BIN     := bin
SRC     := src
# INCLUDE := includes
# LIB     := lib
# LIBRARIES   := 
EXECUTABLE  := luhn


all: $(BIN)/$(EXECUTABLE)

# run: clean all
# 	clear
# 	@echo "🚀 Executing..."
# 	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(SRC)/*.cpp
	@echo "🚧 Building..."
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	@echo "🧹 Clearing..."
	-rm $(BIN)/*
