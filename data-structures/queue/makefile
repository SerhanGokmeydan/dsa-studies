CXX = g++
CXXFLAGS = -Iinclude

bin/main.out: bin/main.o bin/queue-array.o bin/queue-list.o
	$(CXX) $^ -o $@

bin/main.o: src/main.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $^ -o $@

bin/queue-array.o: src/queue-array.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $^ -o $@

bin/queue-list.o: src/queue-list.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@rm -rf bin *.o *.out
