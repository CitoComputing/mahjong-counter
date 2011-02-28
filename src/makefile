CC=g++
CFLAGS=-C -Wall
LDFLAGS=
SOURCES=main.cpp
OBJECTS=$(SOURCES: .cpp=.o)
EXECUTABLE=mahjong-counter

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
