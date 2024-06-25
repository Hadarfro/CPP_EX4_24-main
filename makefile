# /*
#  * Author: Hadar Froimowich.
#  * ID: 213118458
#  * Email: hadarfro12@gmail.com
#  */
CXX = clang++
CXXFLAGS = -std=c++11 -Werror -Wsign-conversion 
VALGRIND_FLAGS = -v --leak-check=full --show-leak-kinds=all --error-exitcode=99
# SFML Libraries
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Sources and objects
DEMO_SOURCES = tree.cpp node.cpp Demo.cpp
GUI_SOURCES = GUI.cpp

DEMO_OBJECTS = $(DEMO_SOURCES:.cpp=.o)
GUI_OBJECTS = $(GUI_SOURCES:.cpp=.o)

# Targets
all: demo gui

demo: $(DEMO_OBJECTS)
	$(CXX) $(CXXFLAGS) $(DEMO_OBJECTS) -o demo $(SFML_LIBS)

gui: $(GUI_OBJECTS)
	$(CXX) $(CXXFLAGS) $(GUI_OBJECTS) -o gui $(SFML_LIBS)

test: TestCounter.o Test.o $(filter-out Demo.o, $(DEMO_OBJECTS))
	$(CXX) $(CXXFLAGS) -v $^ -o $@

tidy:
	clang-tidy $(DEMO_SOURCES) $(GUI_SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f *.o demo test gui
