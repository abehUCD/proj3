#include <gtest/gtest.h> 	  			 	 
#include "SixMensMorrisBoard.h"

TEST(SixMensMorrisBoardTest, DefaultBoardTest){
    // Needs to test that default board is correct
	CSixMensMorrisBoard board;
	int UnplacedR = board.UnplacedPieces('R');
	int UnplacedW = board.UnplacedPieces('W');

	EXPECT_TRUE(UnplacedR == SIX_MENS_MORRIS_PIECES);
	EXPECT_TRUE(UnplacedW == SIX_MENS_MORRIS_PIECES);

	EXPECT_EQ(board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_R);
	for (int index = 0; index < SIX_MENS_MORRIS_POSITIONS; index++) {
		EXPECT_EQ(board.PlayerAtPosition(index), SIX_MENS_MORRIS_EMPTY);
	}
	EXPECT_EQ(std::string(board), ">RU:6 RC:0  WU:6 WC:0\n" //Added two spaces between legend and board
								  "o---------o---------o      0---1---2\n"
								  "|         |         |      | 3-4-5 |\n"
								  "|         |         |      6-7   8-9\n"
								  "|    o----o----o    |      | A-B-C |\n"
								  "|    |         |    |      D---E---F\n"
								  "|    |         |    |        LEGEND\n"
								  "o----o         o----o\n"
								  "|    |         |    |\n"
								  "|    |         |    |\n"
								  "|    o----o----o    |\n"
								  "|         |         |\n"
								  "|         |         |\n"
								  "o---------o---------o\n"
																);
	//EXPECT_FALSE(board.GameOver());
	EXPECT_EQ(std::string(board), board.ToString());
}

TEST(SixMensMorrisBoardTest, SetBoardTest){
    // Needs to test that setting board is correct
	//discussion code
	char turn = SIX_MENS_MORRIS_PLAYER_W;
	int unplaced[SIX_MENS_MORRIS_PLAYERS] = { 2,3 };
	char positions[SIX_MENS_MORRIS_POSITIONS] = { SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
												  SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
												  SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
												  SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
												  SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_R
																															};
	char previous[SIX_MENS_MORRIS_POSITIONS] = { SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_PLAYER_R,
												 SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
												 SIX_MENS_MORRIS_PLAYER_W, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_PLAYER_W,
												 SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY,
											     SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY
	};
	CSixMensMorrisBoard board(turn, unplaced, positions, previous);
	//EXPECT_EQ(board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_W);
	for(int index = 0; index < SIX_MENS_MORRIS_POSITIONS; index++){
		EXPECT_EQ(board.PlayerAtPosition(index), positions[index]);
	EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R), unplaced[0]);
	EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W), unplaced[1]);
	EXPECT_EQ(std::string(board), ">RU:6 RC:0  WU:6 WC:0\n"
								  "o---------o---------o      0---1---2\n"
								  "|         |         |      | 3-4-5 |\n"
								  "|         |         |      6-7   8-9\n"
								  "|    o----o----o    |      | A-B-C |\n"
								  "|    |         |    |      D---E---F\n"
								  "|    |         |    |        LEGEND\n"
								  "o----o         o----o\n"
								  "|    |         |    |\n"
								  "|    |         |    |\n"
								  "|    o----o----o    |\n"
								  "|         |         |\n"
								  "|         |         |\n"
								  "o---------o---------o\n"
																);
	EXPECT_EQ(std::string(board), board.ToString());
	}							  
}

TEST(SixMensMorrisBoardTest, ResetBoardTest){
    // Needs to test that resetting to default board is correct
	// Same chunk of code from the default board, because that's what resetting the board should do
	CSixMensMorrisBoard board;
	int UnplacedR = board.UnplacedPieces('R');
	int UnplacedW = board.UnplacedPieces('W');

	EXPECT_TRUE(UnplacedR == SIX_MENS_MORRIS_PIECES);
	EXPECT_TRUE(UnplacedW == SIX_MENS_MORRIS_PIECES);

	EXPECT_EQ(board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_R);
	for (int index = 0; index < SIX_MENS_MORRIS_POSITIONS; index++) {
		EXPECT_EQ(board.PlayerAtPosition(index), SIX_MENS_MORRIS_EMPTY);
	}
	EXPECT_EQ(std::string(board), ">RU:6 RC:0  WU:6 WC:0\n" //Added two spaces between legend and board
		                          "o---------o---------o      0---1---2\n"
		                          "|         |         |      | 3-4-5 |\n"
		                          "|         |         |      6-7   8-9\n"
		                          "|    o----o----o    |      | A-B-C |\n"
		                          "|    |         |    |      D---E---F\n"
		                          "|    |         |    |        LEGEND\n"
		                          "o----o         o----o\n"
		                          "|    |         |    |\n"
		                          "|    |         |    |\n"
		                          "|    o----o----o    |\n"
		                          "|         |         |\n"
		                          "|         |         |\n"
		                          "o---------o---------o\n"
	                                                             );
	//EXPECT_FALSE(board.GameOver());
	EXPECT_EQ(std::string(board), board.ToString());
}

TEST(SixMensMorrisBoardTest, PlacementTest){
    // Needs to test that normal placement is correct
}

TEST(SixMensMorrisBoardTest, PlacementMillTest){
    // Needs to test that placement creating a mill is correct with removal
}

TEST(SixMensMorrisBoardTest, MoveTest){
    // Needs to test that movement is correct
}

TEST(SixMensMorrisBoardTest, MoveMillTest){
    // Needs to test that movement creating a mill is correct with removal
}
                                       
TEST(SixMensMorrisBoardTest, TwoPieceGameOverTest){
    // Needs to test that game over is correct when only two pieces left
}

TEST(SixMensMorrisBoardTest, NoMoveGameOverTest){
    // Needs to test that game over is correct when no movement allowed
}

TEST(SixMensMorrisBoardTest, BadParametersTest){
    // Needs to test that correct return upon bad parameters
}

