//required libraries
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

std::string DefaultProblemSet()
{
    return "small";
}

int MaxTotalTime(const std::vector<int>& minutes,
                 int limit)
{
   /* implement your algorithm here */
  int current_limit;
  int total_time = 0;
  int last_inserted_index = 0;
  int min_val;
  int n = minutes.size();
  std::vector<int> dp;
  std::vector<int> lowest_dp;

  if (n == 0){
    return 0;
  }

  for (int i=0; i<n; i++) 
  {
    if (minutes[i] > limit){
      if (i == 0){
        last_inserted_index = i-1;
        dp.push_back(total_time);
      }
      else{
        dp.push_back(dp[i-1]); 
      }
      continue;
    }
    
    if (i == 0)
    {
      total_time = total_time + minutes[i]; 
      dp.push_back(total_time); 
      last_inserted_index = 0;
    }
    
    else if (i == 1)
    {
      if (minutes[i] + minutes[i-1] <= limit)
      {
        total_time = total_time + minutes[i];
        dp.push_back(total_time);
        last_inserted_index = i;
      }
      else
      {
        if (minutes[i] > minutes[i-1]){
          total_time = (total_time - dp[i-1])+ minutes[i];
          dp.push_back(total_time);
          last_inserted_index = i;
        }
        else if (dp[i-1] != 0){
          dp.push_back(dp[i-1]);
          last_inserted_index = i-1;
        }
        else{
          total_time = total_time + minutes[i];
          dp.push_back(total_time); 
          last_inserted_index = i;
        }
      }
    }
    else{
      if (i - last_inserted_index >= 2){
        total_time = total_time + minutes[i];
        dp.push_back(total_time);
        last_inserted_index = i;
      }
      else{
        if (i - last_inserted_index == 1){
          
          if (minutes[i]+minutes[last_inserted_index] <= limit){
            total_time = total_time + minutes[i];
            dp.push_back(total_time);
            last_inserted_index = i;
          }
        else if (minutes[i]+minutes[last_inserted_index] > limit)          {
            if (minutes[i]+dp[i-2] > dp[i-1]){
              total_time = minutes[i]+dp[i-2];
              dp.push_back(total_time);
              last_inserted_index = i;
            }
            else{
              if (dp[i-2]+minutes[i] <= dp[i-1]){
                dp.push_back(dp[i-1]);
              }
            }
          }
        }
      }
    }
  }
  return total_time;
  }
