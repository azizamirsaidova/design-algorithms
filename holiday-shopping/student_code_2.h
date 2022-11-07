///////////////////////////////////////////////
// You need to
//    1. Carefully read the instructions.
//    2. Implement function MinCost.
//    3. Compile your code.
//    4. Run the executable on small and large
//       unit tests.
//    5. Test and debug your code. 
//       Make sure that your program does not 
//       have any memory leaks.
//    6. Remove all commented out code. 
//       Double check that your program does
//       not print any debug information on 
//       the screen.
//    7. Submit your source code 
//       ("student_code_2.h") on Canvas.
///////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//you can include standard C++ libraries here

struct Price
{
   int sale {0};
   int after {0};
   int before {0};
};

std::string DefaultProblemSet()
{
    return "small";
}

int MinCost(const std::vector<Price>& giftPrices, int k)
{
  int sum = 0;
  std:: vector<int>difference;

  if (k > giftPrices.size()){
    k = giftPrices.size();
  }

  for (int i=0; i<giftPrices.size(); i++)
  {  
    if (giftPrices[i].before < giftPrices[i].after)
    {
      sum += giftPrices[i].before;
      if (giftPrices[i].sale < giftPrices[i].before){
        difference.push_back(giftPrices[i].sale-giftPrices[i].before);
      }
      else
      {
      difference.push_back(0);
      }
    }
    else
    {
      sum += giftPrices[i].after;
      if (giftPrices[i].sale < giftPrices[i].after)
      {
        difference.push_back(giftPrices[i].sale-giftPrices[i].after);
      }
      else
      {
        difference.push_back(0);
      }
    }
  }
  
  std::nth_element(difference.begin(), difference.begin()+k,difference.end());
  sum+=std::accumulate(difference.begin(), difference.begin()+k,0);

  return sum;
}

