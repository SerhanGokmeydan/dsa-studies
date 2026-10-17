CXX = g++

all: bin/delete-elm.out bin/insert-elm.out

bin/delete-elm.out: bin/delete-elm.o
	$(CXX) $^ -o $@

bin/insert-elm.out: bin/insert-elm.o
	$(CXX) $^ -o $@

bin/delete-elm.o: delete-elm.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

bin/insert-elm.o: insert-elm.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

clean:
	@rm -rf bin *.o *.out
