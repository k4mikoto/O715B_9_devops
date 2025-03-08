CXX = g++
CXXFLAGS = -std=c++11 -Wall -Include
LDFLAGS = -lm

# Names
TARGET = main

# Files
SRC = src/main.cpp

all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC) $(LDFLAGS)
	
clean:
	rm -f $(TARGET)

install:
	install -Dm 755 $(TARGET) $(DESTDIR)/usr/bin/$(TARGET)
