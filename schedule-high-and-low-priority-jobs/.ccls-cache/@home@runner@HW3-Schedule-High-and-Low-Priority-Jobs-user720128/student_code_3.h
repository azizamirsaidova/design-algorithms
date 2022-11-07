///////////////////////////////////////////////
// You need to
//    1. Carefully read the instructions.
//    2. Implement function FindOptimalSchedule.
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
//       ("student_code_3.h") on Canvas.
///////////////////////////////////////////////

// required libraries
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
// you can include standard C++ libraries here

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
