CXX = g++

bin/main.out: bin/insertion-sort.o bin/main.o
	$(CXX) $^ -o $@

bin/main.o: main.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

bin/insertion-sort.o: insertion-sort.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

clean:
	rm -rf bin *.o main.out
