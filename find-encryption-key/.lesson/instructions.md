# Instructions  

**Problem 2.** Alice and Bob are planning to go to a restaurant to celebrate Alice's birthday. Alice chose a place from a list of restaurants (`restaurantList`), encrypted the name of this place using a ToyCrypt cipher, and then sent the encrypted name to Bob. Bob received the encrypted message. However, he does not know the encryption key, so he cannot decrypt the message. Your goal is to write a computer program that finds the key.

The ToyCrypt cipher uses keys that are integer numbers from 0 to _n_, where n is a parameter
which is less than 100,000. Hence, you can find the key using the exhaustive search. In other words, you can try all possible keys from 0 to _n_ and return the one that decrypts the message. To decrypt the message use function

```cpp
std::string decrypt(const std::vector<int>& encryptedName, int key),
```

which decrypts message `encryptedName` using key `key`. You can assume that the message is decrypted correctly if the resulting string is in the list of restaurants `restaurantList`.
Please, implement the following function
```cpp
FindKey(const std::vector<int>& encryptedName, int n, const std::string& restaurantList)
```
Function `FindKey` should return the key that was used by Alice to encode the restaurant name.
The arguments of the function are as follows:
* `const std::vector<int>& encryptedName` &mdash; the encrypted message;
* `int n` &mdash; the maximum possible value of the key (i.e., the key must be an integer in the range
from 0 to _n_);
* `const std::string& restaurantList` &mdash; the list of restaurants separated by ";".

Your program should be fast! It should pass all tests in no more than 5 seconds.

************************
Compile your code!

You can use any standard C++ compiler to compile your code. We recommend using `clang++`. To compile your code, please type `make` or, alternatively, 

```
clang++ -std=c++17 -pedantic-errors -O3 main.cpp -o main
```
************************

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


************************
Submit your code!

After you tested your code, please, download 
``student_code_1.h`` and submit it on Canvas! Make sure that this file does not contain any commented out code. Also, please, check that your code does not print any debug output.