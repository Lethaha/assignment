CC=g++ -std=c++11
CFLAGS=-c
LIBS=-lboost_program_options
SOURCES=Driver.cpp cmdline_parser.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=exec

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) $(LIBS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *o $(EXECUTABLE)

