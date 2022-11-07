all: main

CXX = clang++
CXXFLAGS = -std=c++17 -pedantic-errors -g -Wno-everything 
SANITIZER = -fsanitize=address -fno-omit-frame-pointer
OPT = -O3

SRCS = main.cpp
STUDENT = student_code_2.h
main: $(SRCS) $(STUDENT) 
	$(CXX) $(OPT) $(CXXFLAGS) $(SRCS) -o "$@"

memtest: $(SRCS) $(STUDENT) 
	$(CXX) $(OPT) $(CXXFLAGS) $(SANITIZER) $(SRCS) -o "$@"

main-debug: $(SRCS) $(STUDENT) 
	$(CXX) $(CXXFLAGS) $(SRCS) -o "$@"

clean:
	rm -f main main-debug memtest