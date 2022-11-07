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
//       ("student_code_3.h") on Canvas.
///////////////////////////////////////////////

//required libraries
#include <string>
#include <vector>

//you can include standard C++ libraries here

std::string DefaultProblemSet()
{
    return "small";
}

struct Job
{
   int start;
   int finish;
};


int FindOptimalSchedule(std::vector<Job> highPriorityJobs, std::vector<Job> lowPriorityJobs)
{
   return -1; /* your answer */
}

