**Problem 1.** Bob is a pilot at A336 airlines. He is selecting his schedule for the next `N` days. To do so, he needs to decide on what days he is going to fly and what days he is going to rest. If he flies on day `i`, the flight will take `minutes[i]` minutes. According to the regulations, he cannot fly more than `limit` minutes on two consecutive days. Design an algorithm that picks the days when Bob should fly to maximize the total flight time.


```cpp
int MaxTotalTime(const std::vector<int>& minutes, int limit)
```
The function should return the maximum number of minutes Bob can fly in the next `N` days, where `N` is the size of vector `minutes`.

Your program should be fast! It should pass all tests in no more than 50ms.

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
``student_code_4.h`` and submit it on Canvas! Make sure that this file does not contain any commented out code. Also, please, check that your code does not print any debug output.