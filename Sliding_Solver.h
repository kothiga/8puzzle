#ifndef SLIDING_SOLVER_H
#define SLIDING_SOLVER_H

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <list>
#include <time.h>
#include "Board_Tile.h"

//##############################################################//
//    File : Sliding_Solver.h                                   //
// Purpose : To Take in 2 Board_Tile objects                    //
//           (A start Board, and an End) and find the shortest  //
//           number of steps to get to that End Configuration   //
// Creator : Austin Kothig                                      //  
//    Date : December 3, 2016                                   //
//##############################################################//
class Sliding_Solver
{
  public:
   //##########################
   //      Constructors
   //##########################
   Sliding_Solver(Board_Tile, Board_Tile);

   //##########################
   // Public Member Functions
   //##########################
   void Solve_Puzzle();

  private:
   //##########################
   //     Private Members
   //##########################
   Board_Tile Start;
   Board_Tile Goal;
   Board_Tile Cur;
   std::priority_queue<Board_Tile, std::vector<Board_Tile>, std::greater<Board_Tile> > Q;
   std::vector<Board_Tile> seen;
};

#endif // Sliding_Solver.h
