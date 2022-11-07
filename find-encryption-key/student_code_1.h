// required libraries
#include <string>
#include <vector>
#include <unordered_set>
// include the test framework 
#include "test_framework.h"

// you can include standard C++ libraries here


std::string DefaultProblemSet() { return "small"; }

// You can use the following function to 
// decrypt a message encryptedName using key.
// Note: This is a toy cipher. It is not secure! 
// Do not use it in practice!
std::string decrypt(const std::vector<int> &encryptedName, int key) {
  constexpr int arrayLength = 26;
  constexpr int alphabetSize = 26;
  constexpr int nCharacters = alphabetSize + 2;
  constexpr int64_t prime = 2147483647;
  constexpr int64_t a = 514229;
  constexpr int64_t b = 347;

  std::string result;
  result.reserve(arrayLength - 1);

  if (encryptedName.size() != arrayLength)
    return result;

  int64_t longKey = abs(key) % prime;
  int64_t salt = abs(encryptedName[0]) % prime;
  int64_t x = (longKey + salt + prime) % prime;
  int delay = (salt % arrayLength);

  while (delay-- > 0) {
    x = (a + b * x) % prime;
  }

  int i = 1;
  int code = 0;
  while ((i < arrayLength) && (code < nCharacters - 1)) {
    x = (a + b * x) % prime;
    assert(x >= 0);
    code = (encryptedName[i] + x) % nCharacters;
    if (code < alphabetSize)
      result += ('a' + code);
    if (code == alphabetSize)
      result += ' ';
    i++;
  }

  return result;
}

int FindKey(const std::vector<int> &encryptedName, int n,
            const std::string &restaurantList) 
{

  std:: string temp = "";
  std:: unordered_set<std::string> subString;

  for (auto &ch : restaurantList)
  {
    if (ch != ';')
    {
      temp = temp + ch;
    }
    else
    {
      subString.insert(temp);
      temp = "";
    }
  }
  
  
  for (int j=0; j<n; j++)
  {
    
    std:: string decrypted = decrypt(encryptedName, j);
    if (subString.find(decrypted) != subString.end())
    {
      return j;
    } 
  }

  
  return -1; 
}
