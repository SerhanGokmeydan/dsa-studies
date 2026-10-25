CXX = g++

bin/main.out: bin/main.o bin/merge-sort.o
	$(CXX) $^ -o $@

bin/main.o: main.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

bin/merge-sort.o: merge-sort.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

clean:
	@rm -rf bin *.o *.out
