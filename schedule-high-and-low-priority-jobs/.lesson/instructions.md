**Problem 2.** Consider a variant of the Interval Scheduling Problem discussed in class. Suppose that we are given two arrays of jobs. The ﬁrst array (`highPriorityJobs`) contains high priority jobs and the second array (`lowPriorityJobs`) contains low priority jobs. Your goal is to design an algorithm that schedules all high priority jobs and the maximum possible number of low priority jobs. Please, implement the following function:
```cpp
int FindOptimalSchedule(std::vector<Job> highPriorityJobs, std::vector<Job> lowPriorityJobs)
```
The function should return the number of scheduled low priority jobs.

Your program should be fast! It should pass all tests in no more than 300ms.

Compile your code!

You can use any standard C++ compiler to compile your code. We recommend using `clang++`. To compile your code, please type `make` or, alternatively, 

```
clang++ -std=c++17 -pedantic-errors -O3 main.cpp -o main
```

Test your code!

Please, run unit tests:
``` 
./main small
./main large
```

We also recommend that you run memory tests:
```
make memtest
./memtest small
./memtest large
```

Submit your code!

After you tested your code, please, download 
``student_code_1.h`` and submit it on Canvas! Make sure that this file does not contain any commented out code. Also, please, check that your code does not print any debug output.