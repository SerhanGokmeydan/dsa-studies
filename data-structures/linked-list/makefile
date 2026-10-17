CXX = g++
CXXFLAGS = -Iinclude

bin/main.out: bin/main.o bin/linked-list.o
	$(CXX) $^ -o $@

bin/main.o: src/main.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $^ -o $@

bin/linked-list.o: src/linked-list.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@rm -rf bin *.o main.out
