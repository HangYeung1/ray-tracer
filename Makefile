CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment

# Add sanitizer flags for identifying undefined behavior
CXXFLAGS += -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

# Compile the main executable
main.exe: Vector3d.cpp Color.cpp main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump