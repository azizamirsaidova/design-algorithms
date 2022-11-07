// required libraries
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

std::string DefaultProblemSet() { return "small"; }

struct Job {
  int start;
  int finish;
};


int FindOptimalSchedule(std::vector<Job> highPriorityJobs,
                        std::vector<Job> lowPriorityJobs) {

  Job curr = {0,0};
  Job currhighPriority = highPriorityJobs[0];
  int counter = 0;
  int totalHighPriorityJobSize = highPriorityJobs.size();
  int highPriorityJobProcessed = 1;
  
  sort(highPriorityJobs.begin(), highPriorityJobs.end(),
       [](Job &x, Job &y) { return x.finish < y.finish; });

  sort(lowPriorityJobs.begin(), lowPriorityJobs.end(),
       [](Job &x, Job &y) { return x.finish < y.finish; });
  
  for (int i = 0; i < lowPriorityJobs.size(); i++) {
    if (lowPriorityJobs[i].finish <= currhighPriority.start){
        if (curr.start == 0 && curr.finish == 0){
          curr = lowPriorityJobs[i];
          counter = counter + 1;
          }else if (lowPriorityJobs[i].start  >= curr.finish){
            curr = lowPriorityJobs[i];
            counter = counter+1;
          }
    }else if (lowPriorityJobs[i].start >= currhighPriority.finish ){
      if (highPriorityJobProcessed < totalHighPriorityJobSize){
        curr = currhighPriority;
        currhighPriority = highPriorityJobs[highPriorityJobProcessed];
        highPriorityJobProcessed = highPriorityJobProcessed + 1;
        i = i -1;
      }else{
      if (curr.start == 0 && curr.finish == 0){
          curr = lowPriorityJobs[i];
          counter = counter+ 1;
          }else{
          if (lowPriorityJobs[i].start  >= curr.finish){
            curr = lowPriorityJobs[i];
            counter = counter + 1;
  
          }
        }
      }
    }
  }
  return counter;
}
