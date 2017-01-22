#include "Board_Tile.h"

//#########################//
//                         //
//      Constructors       //
//                         //               
//#########################//
Board_Tile::Board_Tile() {}

Board_Tile::Board_Tile(const std::string& ConfigString)
{
   config(ConfigString);
}

//#########################//
//                         //  
// Public Member Functions //
//                         //
//#########################//

//####################################
// Function : Manhattan_Distance
//  Purpose : Calculate the A* Distance
//            Using Manhattan Distance
//####################################
int Board_Tile::Manhattan_Distance(Board_Tile Goal)
{
   int manhatton = 0;
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
      {
	 int SEARCH = board[i][j];
	 if(SEARCH != 0)
	 {
	    int tempI = Goal.findX(SEARCH);
	    int tempJ = Goal.findY(SEARCH);
	    manhatton += (abs(i-tempI) + abs(j-tempJ));
	 }
      }
   
   // Calculate A* Distance w/ Manhatton Distance
   MD = numMoves() + manhatton;
   return MD;   // This is The A* Distance
}

//####################################
// Function : findX
//  Purpose : return the X coordinate
//            of SEARCH in board
//            (Used for Manhattan D)
//####################################
int Board_Tile::findX(int SEARCH)
{
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
	 if(board[i][j] == SEARCH)
	    return i;
	 
   return 0;
}

//####################################
// Function : findY
//  Purpose : return the Y coordinate
//            of SEARCH in board
//            (Used for Manhattan D)
//####################################
int Board_Tile::findY(int SEARCH)
{
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
	 if(board[i][j] == SEARCH)
	    return j;
	 
   return 0;
}

//####################################
// Function : nextConfigs
//  Purpose : return a list of the
//            possible configurations
//            relative to the '0' tile
//####################################
std::list<Board_Tile> Board_Tile::nextConfigs()
{
   std::list<Board_Tile> ReturnList;

   // search through the board for
   // the tile 0
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
      {
	 if (board[i][j] == 0)
	    // once found, do a switch statement
	    // to return a list of the possible
	    // Moves that can be made
	    switch(i)
	    {
	       case 0:
		  switch(j)
		  {
		     // 0,0
		     case 0:
			ReturnList.push_back(m_BoardSwap(i,j,0,1));
			ReturnList.push_back(m_BoardSwap(i,j,1,0));
			break;

		     // 0,1
		     case 1:
			ReturnList.push_back(m_BoardSwap(i,j,0,0));
			ReturnList.push_back(m_BoardSwap(i,j,0,2));
			ReturnList.push_back(m_BoardSwap(i,j,1,1));
			break;

		     // 1,2
		     case 2:
			ReturnList.push_back(m_BoardSwap(i,j,0,1));
			ReturnList.push_back(m_BoardSwap(i,j,1,2));
			break;
		  }
		  break;
	       
	       case 1:
		  switch(j)
		  {
		     // 1,0
		     case 0:
			ReturnList.push_back(m_BoardSwap(i,j,0,0));
			ReturnList.push_back(m_BoardSwap(i,j,1,1));
			ReturnList.push_back(m_BoardSwap(i,j,2,0));
			break;

		     // 1,1
		     case 1:
			ReturnList.push_back(m_BoardSwap(i,j,0,1));
			ReturnList.push_back(m_BoardSwap(i,j,1,0));
			ReturnList.push_back(m_BoardSwap(i,j,1,2));
			ReturnList.push_back(m_BoardSwap(i,j,2,1));
			break;
			
		     // 1,2
		     case 2:
			ReturnList.push_back(m_BoardSwap(i,j,0,2));
			ReturnList.push_back(m_BoardSwap(i,j,1,1));
			ReturnList.push_back(m_BoardSwap(i,j,2,2));
			break;
		     
		  }
		  break;

	       case 2:
		  switch(j)
		  {
		     // 2,0
		     case 0:
			ReturnList.push_back(m_BoardSwap(i,j,1,0));
			ReturnList.push_back(m_BoardSwap(i,j,2,1));
			break;

		     // 2,1
		     case 1:
			ReturnList.push_back(m_BoardSwap(i,j,2,0));
			ReturnList.push_back(m_BoardSwap(i,j,1,1));
			ReturnList.push_back(m_BoardSwap(i,j,2,2));
			break;

		     // 2,2
		     case 2:
			ReturnList.push_back(m_BoardSwap(i,j,2,1));
			ReturnList.push_back(m_BoardSwap(i,j,1,2));
			break;
		  }
		  break;
	    }		     
      }
   
   return ReturnList;
}

//####################################
// Function : PrintGoal
//  Purpose : Function used to pretty
//            up interface and give
//            a visual representation
//            of what was started
//            and what was ended
//####################################
void Board_Tile::PrintGoal(Board_Tile Goal) const
{
   std::cout << "\n"
	     << "          " << board[0][0] << " " << board[0][1] << " " << board[0][2]
	     << "        " << Goal.board[0][0] << " " << Goal.board[0][1] << " " << Goal.board[0][2] << "\n"
	     << "          " << board[1][0] << " " << board[1][1] << " " << board[1][2]
	     << "   ->   " << Goal.board[1][0] << " " << Goal.board[1][1] << " " << Goal.board[1][2] << "\n"
	     << "          " << board[2][0] << " " << board[2][1] << " " << board[2][2]
	     << "        " << Goal.board[2][0] << " " << Goal.board[2][1] << " " << Goal.board[2][2] << "\n\n";
}

//####################################
// Function : numMoves
//  Purpose : returns the length of
//            Moves_From_Start, which
//            is the number of moves
//            to get from start->end
//####################################
int Board_Tile::numMoves() const
{
   return Moves_From_Start.length();
}

//####################################
// Function : Solution
//  Purpose : Returns The Moves_From_Start
//            variable, which is the
//            order of moves U/D/R/L
//####################################
std::string Board_Tile::Solution() const
{
   return Moves_From_Start;
}

//####################################
// Function : config
//  Purpose : Does an Error Check, Then
//            Converts the string of
//            characters to be integers
//            in the Board
//####################################
void Board_Tile::config(std::string inConfig)
{
   inConfig = m_errorCheck(inConfig);
   int cur = 0;
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
      {
	 board[i][j] = m_CharToInt(inConfig[cur]);
	 cur++;
      }
}


//#########################//
//                         //
// Public Member Operators //
//                         //
//#########################//

//####################################
// Function : == Operator
//  Purpose : Compares ONLY the
//            Boards of two Board_Tile
//            objects
//####################################
bool Board_Tile::operator == (Board_Tile inBoard) const
{
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
	 if(board[i][j] != inBoard.board[i][j])
	    return false;
   return true;
}

//####################################
// Function : > Operator
//  Purpose : Compares Manhatton
//            Distances of Two Boards
//            (Essential for pq)
//####################################
bool Board_Tile::operator > (Board_Tile inBoard) const
{
   return MD > inBoard.MD;
}

//####################################
// Function : = Operator
//  Purpose : Sents a Board to
//            be another
//####################################
void Board_Tile::operator = (Board_Tile inBoard)
{
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
	 board[i][j] = inBoard.board[i][j];
   MD = inBoard.MD;
   Moves_From_Start = inBoard.Moves_From_Start;
}


//##########################//
//                          //
// Private Member Functions //
//                          //
//##########################//
   
//####################################
// Function : m_errorCheck
//  Purpose : Private function to
//            check if input is propper
//            (Doesn't check dublicates)
//####################################
std::string Board_Tile::m_errorCheck(std::string inString)
{
   if(inString.length() == 9)
   {
      for(int i = 0; i < inString.length(); i++)
      {
	 if(!(m_CharToInt(inString[i]) <= 8 && m_CharToInt(inString[i]) >= 0))
	 {
	    std::cout << "\n"
		      << "Invalid Configuration : Illegal Character '"
		      << inString[i] << "' Not Allowed!!\n"
		      << "Please Try Again . . .\n"
		      << "\n   Enter a Configuration to be Solved . . .\n"
		      << "    Ex. '123456780'\n\n   Config : ";
	    std::string newString;
	    std::cin >> newString;
	    return m_errorCheck(newString);
	    break;
	 }
      }
      return inString;
   }
   
   else
   {
      std::cout << "\n"
		<< "Invalid Configuration : Improper Number of Characters!!\n"
		<< "Please Try Again . . .\n"
		<< "\n   Enter a Configuration to be Solved . . .\n"
		<< "    Ex. '123456780'\n\n   Config : ";
      std::string newString;
      std::cin >> newString;
      return m_errorCheck(newString);
   }       
}

//####################################
// Function : m_CharToInt
//  Purpose : Private Function to turn
//            a char into an int
//####################################
int Board_Tile::m_CharToInt(char C)
{
   return C-'0';
}

//####################################
// Function : m_BoardSwap
//  Purpose : Private Function to help
//            facilitate the swapping
//            if tile locations.
//            Also Appends the Move
//####################################
Board_Tile Board_Tile::m_BoardSwap(int a, int b, int c, int d)
{
   Board_Tile ReturnBoard = *this;

   // swap the two tiles
   int temp;
   temp = ReturnBoard.board[a][b];
   ReturnBoard.board[a][b] = ReturnBoard.board[c][d];
   ReturnBoard.board[c][d] = temp;  

   // Add the Move that was Made
   if(a > c)     {ReturnBoard.Moves_From_Start += "U";}
   else if(c > a){ReturnBoard.Moves_From_Start += "D";}
   else if(b > d){ReturnBoard.Moves_From_Start += "L";}
   else if(d > b){ReturnBoard.Moves_From_Start += "R";}

   return ReturnBoard;
}

//####################################
// Function : << Operator
//  Purpose : Allow the priting
//            of Board_Tile Objects
//####################################
std::ostream& operator << (std::ostream& out, Board_Tile outBoard)
{
   for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++) 
	 out << outBoard.board[i][j];
}
