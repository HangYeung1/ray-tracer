CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment

# Add sanitizer flags for identifying undefined behavior
CXXFLAGS += -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG\

# Define the prequisite files
UTILITY ?= Color.hpp Interval.cpp
OBJECTS ?= Vector3d.cpp Ray.cpp Hittable.hpp HittableList.cpp Sphere.cpp

# Render image
render: main.exe
	./main.exe > image.ppm

# Compile the main executable
main.exe: $(UTILITY) $(OBJECTS) main.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump