src = $(wildcard src/*.cpp)
lib = -lncurses

dance: $(src)
	g++ -o $@ $^ $(lib)

clean:
	rm -fr ./dance
