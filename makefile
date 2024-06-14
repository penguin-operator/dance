lib = -lncurses

all: dance

dance:
	g++ -o $@ src/main.cpp $(lib)

clean:
	rm -fr ./dance
