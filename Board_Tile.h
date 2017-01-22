#ifndef BOARD_TILE_H
#define BOARD_TILE_H

#include <iostream>
#include <string>
#include <cmath>
#include <list>

//##############################################################//
//    File : Board_Tile.h                                       //
// Purpose : The Objective Representation of a single state     //
//           of a possible board. Bulk of the implementation    //
//           is here.                                           //
// Creator : Austin Kothig                                      //
//    Date : December 3, 2016                                   //
//##############################################################//
class Board_Tile
{
  public:
   //##########################
   //      Constructors
   //##########################
   Board_Tile();                    // For Creating uninitialized Boards
   Board_Tile(const std::string&);  // For Constructing known Boards
   
   
   //##########################
   // Public Member Functions
   //##########################
   int Manhattan_Distance(Board_Tile);
   int findX(int);
   int findY(int);
   std::list<Board_Tile> nextConfigs();
   void PrintGoal(Board_Tile) const;
   int numMoves() const;
   std::string Solution() const;
   void config(std::string);
   

   //##########################
   // Public Member Operators
   //##########################
   bool operator == (Board_Tile) const;
   bool operator > (Board_Tile) const;
   void operator = (Board_Tile);
   friend std::ostream& operator << (std::ostream&, Board_Tile);

  private:
   //##########################
   // Private Member Functions
   //##########################
   std::string m_errorCheck(std::string);
   int m_CharToInt(char);
   Board_Tile m_BoardSwap(int, int, int, int);
   
   //##########################
   //     Private Members
   //##########################
   int board[3][3];
   int MD = 0;
   std::string Moves_From_Start = "";
   
};

#endif // Board_Tile.h
