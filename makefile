src = $(wildcard src/*.cpp)
lib = -lncurses

all: dance

dance: $(src)
	g++ -o $@ $^ $(lib)

clean:
	rm -fr ./dance
