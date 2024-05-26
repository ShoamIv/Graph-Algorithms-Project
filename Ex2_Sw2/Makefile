
#id:206698359    mail:shoamivgi1234@gmail.com
CXX=clang++
CXXFLAGS=-std=c++11 -Werror
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCES=Algorithms.cpp Belman_Ford.cpp BFS.cpp Bipartite.cpp Test.cpp TestCounter.cpp DFS.cpp Dijkstra.cpp Graph.cpp Traverse.cpp Linear_Algebra.cpp
OBJECTS=$(subst .cpp,.o,$(SOURCES))

runtest: test
		./test

test: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o  demo test
 