CXXFLAGS = --std=c++11 `pkg-config saftlib --cflags`
LDFLAGS  = `pkg-config saftlib --libs`

all: saft-snoop-saftbus saft-snoop-standalone
saft-snoop-saftbus:    saft-snoop-saftbus.cpp
saft-snoop-standalone: saft-snoop-standalone.cpp

.PHONY: clean
clean:
	rm -f saft-snoop-saftbus saft-snoop-standalone