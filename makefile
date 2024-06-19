src = $(wildcard src/*.cpp)
lib = -lncurses

all: dance

dance: $(src)
	@g++ -o $@ $^ $(lib) -Wall

clean:
	@rm -fr ./dance
