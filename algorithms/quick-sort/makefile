CXX = g++

bin/main.out: bin/main.o bin/quick-sort.o
	$(CXX) $^ -o $@

bin/main.o: main.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

bin/quick-sort.o: quick-sort.cpp
	@mkdir -p bin
	$(CXX) -c $^ -o $@

clean:
	@rm -rf bin *.o *.out
