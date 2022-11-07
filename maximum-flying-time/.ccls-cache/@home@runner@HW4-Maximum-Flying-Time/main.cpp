/////////////////////////////////////////////////
// DO NOT EDIT THIS FILE

#include "student_code_4.h"
#include <string>
#include <vector>
#include "test_framework.h"

const char* smallDataset = "small_problem_set_4.in";
const char* largeDataset = "large_problem_set_4.in";

const char *helpMsg = 
   "Please, indicate which problem set to use.\n\n"
   "For small problem set,"
      " type: ./problem_solver_3 small\n"
   "For large problem set, type:"
      " ./problem_solver_3 large\n";

const char *strNotice = 
   "##################################\n"
   "# Do not edit this file!\n"
   "##################################\n";

constexpr int problem_set_id = 4;

struct ProblemN4: public TestFramework::BasicProblem
{
   std::vector<int> minutes;
   int limit;
};

int main(int argc, char *argv[])
{
   using namespace TestFramework;

   static_assert(
      GetTestFrameworkVersion() == 8,
      "TestFramework version 8 is required."
      "Please, update test_framework.h.");

   if ((argc != 2) && (argc != 3)) 
   {
       std::cout << helpMsg;
   }

   std::string firstArg(DefaultProblemSet());

   if (argc >= 2) 
   {
      firstArg = argv[1];
   }
   else 
   {
      std::cout << "\nUsing the default problem set: "
                << firstArg;
   }

   ExitIfConditionFails((firstArg == "small") || 
                        (firstArg == "large"),
                         "Unknown problem set.");
   bool bSmallDataset = (firstArg == "small");

   std::cout << std::endl << "Problem set #" 
             << problem_set_id << ". ";

   ProblemSetHeader header;
   RecordAdapter<ProblemSetHeader> psAdapter(header);
   AddDefaultProblemSetColumns(psAdapter);
   std::vector<ProblemN4> problems;
   TableAdapter<ProblemN4> prAdapter(problems);
   AddDefaultProblemColumns(prAdapter);

   AddColumn<ProblemN4>(prAdapter, "minutes", 
                        &ProblemN4::minutes);
    
   AddColumn<ProblemN4>(prAdapter, "limit", 
                        &ProblemN4::limit);

   BasicYamlParser parser(
       dynamic_cast<ITable*>(&psAdapter),
       dynamic_cast<ITable*>(&prAdapter));

   const char* inputFilename = bSmallDataset ?
                       smallDataset : largeDataset;
   std::cout << "File: " << inputFilename << ".\n";

   parser.ParseFile(inputFilename, true);
   PreprocessProblemSet(problem_set_id, problems, 
                        header);

   for (int i = 0; i < problems.size(); ++i)
   {
      auto& theProblem = problems[i];
      theProblem.student_answer = MaxTotalTime(theProblem.minutes, theProblem.limit);
   }

    ProcessResults(problems, header);

   std::cout << "Don't forget to submit your "
                "source code on Canvas.";
    
   std::cout << "\nRunning time: " << header.time 
             << "ms";
    
   std::cout << std::endl << std::endl;
   std::cout << std::endl << std::endl;

   if (argc == 3)
   {
      const char * outputFilename = argv[2];
      std::cout << "Generating a report. ";
      std::cout << "The report is saved in file '" 
                << outputFilename << "'.\n";
       
      TableAdapter<ProblemN4> prOutAdapter(problems);
      AddDefaultProblemColumnsForOutput(prOutAdapter);

      WriteTableToFile(outputFilename, &prOutAdapter,
                       &psAdapter, true, strNotice);
   }

   return 0;
}
