#include "Sliding_Solver.h"


//#########################//
//                         //
//      Constructors       //
//                         //               
//#########################//
Sliding_Solver::Sliding_Solver(Board_Tile s, Board_Tile g)
{
   Start = s;
   Goal = g;
   Cur = s;
}


//#########################//
//                         //  
// Public Member Functions //
//                         //
//#########################//

//####################################
// Function : Solve_Puzzle
//  Purpose : Meat and Potatoes of 
//            the Solving
//####################################
void Sliding_Solver::Solve_Puzzle()	    
{
   clock_t startTime = clock();
   // if the Current Board_Tile is not
   // the solution, then . . .
   while(!(Cur == Goal))
   {
      // get a list of the next configurations
      std::list<Board_Tile> nextConfigs = Cur.nextConfigs();

      // iterate through the received list and add any new unique configurations to the queue
      for(std::list<Board_Tile>::iterator i = nextConfigs.begin(); i != nextConfigs.end(); i++)
      {
	 // simple check to see if i has been seen before
	 bool found = false;
	 for(int j = 0; j < seen.size(); j++)
	 if(seen[j] == *i)
	 {
	    found == true; // i is a duplicate, stop searching, dont add
	    break;
	 }

	 // add a new Board_Tile to the queue
	 if(!found)
	 {
	    i->Manhattan_Distance(Goal); // set i's MD
	    seen.push_back(*i);          // add i to the seen
	    Q.push(*i);                  // add i to the queue
	 } 
      }

      Cur = Q.top(); // set new Current
      Q.pop();       // get rid of the top

      // This line is for seeing what is happening under the hood
      //std::cout << seen.size() << " " << Cur << " " << Cur.Manhattan_Distance(Goal) << " " << Cur.numMoves() << " " << Cur.Solution() << "\n";
      
   } // while loop is broken when goal is found

   //calc the elapsed time
   clock_t result = ((clock() - startTime)/ (1000.0));
   
   // Print the start board and end board
   Start.PrintGoal(Goal);
   
   // Simplistic Layout for the Goal Configuration
   std::cout << "       Start Board : " << Start << "\n"
	     << "        Goal Board : " << Goal << "\n"
	     << "   Number of Moves : " << Cur.numMoves() << "\n"
	     << "          Solution : " << Cur.Solution() << "\n"
             << "              Time : " << result << " milliseconds" << "\n\n";
	
   
}
