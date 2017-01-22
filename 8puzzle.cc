#include <iostream>
#include <string>
#include "Board_Tile.h"
#include "Sliding_Solver.h"

//##############################################################//
//      File : 8puzzle.cc                                       //
//   Purpose : Main UI design, where the user passes in values  //
//             For the Board_Tile and Sliding_Solver to do all  //
//             the work. (Bread and Butter of the Program)      //
//   Creator : Austin Kothig                                    //
//      Date : December 3, 2016                                 //
//   Compile : Compile with command 'make'                      //
// Referance : Consult the README file for Referances           //
//##############################################################//

using namespace std;

//##################################
//             main
//##################################
int main()
{
   cout << "\n##########################################################\n"
	<< "##########################################################\n";
   cout << "\n"
	<< "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	<< "                 8-Tile Puzzle Solver          \n"
	<< "                 ^^^^^^^^^^^^^^^^^^^^          \n"
	<< "        Purpose : Given a Unique Permutation   \n"
	<< "                  of Numbers between 0 and 8   \n"
	<< "                  which represent an 8-Tile    \n"
	<< "                  Board, it will print the     \n"
	<< "                  steps in order to solve!!    \n"
	<< "       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"
	<< "\n"
	<< "##########################################################\n"
	<< "##########################################################\n\n"
	<< "Use the Default Goal State of '123456780'? (Y / Any Key) : ";
   char askGoal;
   cin >> askGoal;
   Board_Tile Goal;
   if (tolower(askGoal) == 'y')
      Goal.config("123456780");
   else
   {
      cout << "Enter The Goal State You would like : ";
      string NewGoal;
      cin >> NewGoal;
      Goal.config(NewGoal);
   }
   
   cout << "\nEnter The Number of Configuration to be Solved : ";
   int n;
   cin >> n;
   cout << "\n##########################################################\n";
   

   for(int i = 0; i < n; i++)
   {
      cout << "##########################################################\n";

      
      
      cout << "\n   Enter a Configuration to be Solved . . .\n"
	   << "    Ex. '123456780'\n\n   Config : ";

      string inConfig;
      cin >> inConfig;

      Board_Tile Start(inConfig);

      Sliding_Solver Solve(Start, Goal);
      Solve.Solve_Puzzle();
      
      cout << "##########################################################\n";
   }
   cout << "##########################################################\n";
   
   return 0;
}
