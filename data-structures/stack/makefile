CXX = g++
CXXFLAGS = -Iinclude

bin/main.out: bin/main.o bin/stack-array.o bin/stack-list.o
	$(CXX) $^ -o $@

bin/main.o: src/main.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $^ -o $@

bin/stack-array.o: src/stack-array.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $^ -o $@

bin/stack-list.o: src/stack-list.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@rm -rf bin *.o *.out
