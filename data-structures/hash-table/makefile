CXX = g++
CXXFLAGS = -Iinclude

bin/main.out: bin/main.o
	$(CXX) $^ -o $@

bin/main.o: main.cpp
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) -c $^ -o $@

clean:
	@rm -rf bin *.o *.out

