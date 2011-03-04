CXX=g++
CXXFLAGS=-c -Wall
LDFLAGS=-lsqlite3 -lpthread -ldl

OBJ_DIR = obj
BIN_DIR = bin
EXECUTABLE = mahjong-counter

SOURCES = main.cpp Database.cpp actionInit.cpp TileSet.cpp Player.cpp Game.cpp
OBJECTS = $(SOURCES:%.cpp=$(OBJ_DIR)/%.o)

all: dirs $(OBJECTS) $(EXECUTABLE)

dirs:
	mkdir -p $(OBJ_DIR)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o  $(EXECUTABLE)

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm obj/*
