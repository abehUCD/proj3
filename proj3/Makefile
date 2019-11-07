CXX = g++


INCLUDE_DIR	=./include
SRC_DIR	=./src
BIN_DIR	=./bin
OBJ_DIR	=./obj
TESTBIN_DIR =./testbin

CXXFLAGS = -I $(INCLUDE_DIR) -Wall --std=c++14
TESTLDFLAGS = -lgtest -lgtest_main -lpthread

PROJ_OBJS =$(OBJ_DIR)/SixMensMorrisBoard.o
TEST_OBJ = $(OBJ_DIR)/testsixmensmorris.o
MAIN_OBJ = $(OBJ_DIR)/main.o

TEST_NAME = testsixmen
PROJ_NAME = game

all: directories RUNTEST

all: directories $(TESTBIN_DIR)/$(TEST_NAME) $(BIN_DIR)/$(PROJ_NAME)

RUNTEST: $(TESTBIN_DIR)/$(TEST_NAME)
	$(TESTBIN_DIR)/$(TEST_NAME)

$(TESTBIN_DIR)/$(TEST_NAME): $(PROJ_OBJS) $(TEST_OBJ)
	$(CXX) $(PROJ_OBJS) $(TEST_OBJ) -o $(TESTBIN_DIR)/$(TEST_NAME) $(CXXFLAGS) $(TESTLDFLAGS)

$(BIN_DIR)/$(PROJ_NAME): $(PROJ_OBJS) $(MAIN_OBJ)
	$(CXX) $(MAIN_OBJ) $(PROJ_OBJS) -o $(BIN_DIR)/$(PROJ_NAME) $(PROJ_OBJS) $(CXXFLAGS) $(TESTLDFLAGS)

$(OBJ_DIR)/SixMensMorrisBoard.o: $(SRC_DIR)/SixMensMorrisBoard.cpp $(INCLUDE_DIR)/SixMensMorrisBoard.h
	$(CXX) $(CXXFLAGS)  $(SRC_DIR)/SixMensMorrisBoard.cpp -c -o $(OBJ_DIR)/SixMensMorrisBoard.o 

$(TEST_OBJ): $(SRC_DIR)/testsixmensmorris.cpp $(INCLUDE_DIR)/SixMensMorrisBoard.h
	$(CXX) $(SRC_DIR)/testsixmensmorris.cpp -c -o $(OBJ_DIR)/testsixmensmorris.o $(CXXFLAGS)

$(OBJ_DIR)/main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/SixMensMorrisBoard.h
	$(CXX) $(CXXFLAGS)  $(SRC_DIR)/main.cpp -c -o $(OBJ_DIR)/main.o

directories:
	mkdir -p $(BIN_DIR)
	mkdir -p $(OBJ_DIR)
	mkdir -p $(TESTBIN_DIR)

clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(TESTBIN_DIR)/$(TEST_NAME)

