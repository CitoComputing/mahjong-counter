CC=g++
CFLAGS=-C -Wall
LDFLAGS=-lsqlite3 -lpthread -ldl
SOURCES=main.cpp Database.cpp actionInit.cpp TileSet.cpp
OBJECTS=$(SOURCES: .cpp=.o)
EXECUTABLE=mahjong-counter

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm $(EXECUTABLE) $(OBJECTS) 
