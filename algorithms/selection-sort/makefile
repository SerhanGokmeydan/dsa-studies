CXX = g++

bin/main.out: bin/main.o bin/selection-sort.o
	$(CXX) $^ -o $@

bin/main.o: main.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

bin/selection-sort.o: selection-sort.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

clean:
	@rm -rf bin *.o main.out
