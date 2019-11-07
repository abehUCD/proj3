#include <gtest/gtest.h> 	  			 	 
#include "SixMensMorrisBoard.h"
#include <iostream>

TEST(SixMensMorrisBoardTest, DefaultBoardTest) {
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

TEST(SixMensMorrisBoardTest, SetBoardTest) {
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
												 SIX_MENS_MORRIS_PLAYER_R, SIX_MENS_MORRIS_EMPTY, SIX_MENS_MORRIS_EMPTY
	};
	CSixMensMorrisBoard board(turn, unplaced, positions, previous);
	//EXPECT_EQ(board.PlayerTurn(), SIX_MENS_MORRIS_PLAYER_W);
	for (int index = 0; index < SIX_MENS_MORRIS_POSITIONS; index++) {
		EXPECT_EQ(board.PlayerAtPosition(index), positions[index]);
		EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_R), unplaced[0]);
		EXPECT_EQ(board.UnplacedPieces(SIX_MENS_MORRIS_PLAYER_W), unplaced[1]);
		EXPECT_EQ(std::string(board), " RU:2 RC:0 >WU:3 WC:0\n"                  //Changed board from default to the positions as shown above
			"R---------W---------R      0---1---2\n"
			"|         |         |      | 3-4-5 |\n"
			"|         |         |      6-7   8-9\n"
			"|    o----o----o    |      | A-B-C |\n"
			"|    |         |    |      D---E---F\n"
			"|    |         |    |        LEGEND\n"
			"W----o         o----W\n"
			"|    |         |    |\n"
			"|    |         |    |\n"
			"|    o----o----o    |\n"
			"|         |         |\n"
			"|         |         |\n"
			"R---------o---------R\n"
		);
		EXPECT_EQ(std::string(board), board.ToString());
	}
}

TEST(SixMensMorrisBoardTest, ResetBoardTest) {
	// Needs to test that resetting to default board is correct
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

TEST(SixMensMorrisBoardTest, PlacementTest) {
	// Needs to test that normal placement is correct
	CSixMensMorrisBoard board;
	board.Place('R', 0);
	EXPECT_TRUE(board.PlayerAtPosition(0) == 'R');

	EXPECT_EQ(std::string(board), " RU:5 RC:0 >WU:6 WC:0\n" //Added two spaces between legend and board
		"R---------o---------o      0---1---2\n"
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

TEST(SixMensMorrisBoardTest, PlacementMillTest) {
	// Needs to test that placement creating a mill is correct with removal
	CSixMensMorrisBoard board;
	board.Place('R', 0);
	board.Place('W', 3);
	board.Place('R', 1);
	board.Place('W', 4);
	board.Place('R', 2);
	EXPECT_TRUE(board.CanRemove('R'));
	board.Remove('R', 3); //There is an error where if we place a piece on an already occupied spot, it replaces the piece, but does not change the turn.
	EXPECT_EQ(std::string(board), " RU:3 RC:1 >WU:4 WC:0\n" //Added two spaces between legend and board
		"R---------R---------R      0---1---2\n"
		"|         |         |      | 3-4-5 |\n"
		"|         |         |      6-7   8-9\n"
		"|    o----W----o    |      | A-B-C |\n"
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

TEST(SixMensMorrisBoardTest, MoveTest) {
	// Needs to test that movement is correct
	/*if for an arbitray piece of the specfic player:
	there is a free space in any direciton adjacent to it
	then the player can move their piece to which ever free space they choose*/
	CSixMensMorrisBoard board;
	board.Place('R', 0);
	board.Place('W', 2);
	board.Place('R', 1);
	board.Place('W', 3);
	board.Place('R', 4);
	board.Place('W', 9);
	board.Place('R', 6);
	board.Place('W', 10);
	board.Place('R', 7);
	board.Place('W', 12);
	board.Place('R', 11);
	board.Place('W', 13);

	EXPECT_TRUE(board.CanMove('R', 4));
	EXPECT_TRUE(board.Move('R', 4, 5));
	EXPECT_TRUE(board.PlayerAtPosition(5) == 'R');

	EXPECT_EQ(std::string(board), " RU:0 RC:0 >WU:0 WC:0\n" //Added two spaces between legend and board
		"R---------R---------W      0---1---2\n"
		"|         |         |      | 3-4-5 |\n"
		"|         |         |      6-7   8-9\n"
		"|    W----o----R    |      | A-B-C |\n"
		"|    |         |    |      D---E---F\n"
		"|    |         |    |        LEGEND\n"
		"R----R         o----W\n"
		"|    |         |    |\n"
		"|    |         |    |\n"
		"|    W----R----W    |\n"
		"|         |         |\n"
		"|         |         |\n"
		"W---------o---------o\n"
	                               );
	//EXPECT_FALSE(board.GameOver());
	EXPECT_EQ(std::string(board), board.ToString());
}

TEST(SixMensMorrisBoardTest, MoveMillTest) {
	// Needs to test that movement creating a mill is correct with removal
	CSixMensMorrisBoard board;
	board.Place('R', 0);
	board.Place('W', 3);
	board.Place('R', 1);
	board.Place('W', 4);
	board.Place('R', 2);

	EXPECT_TRUE(board.CanRemove('R'));
	EXPECT_TRUE(board.Remove('R', 4));

	//EXPECT_TRUE(UnplacedR == SIX_MENS_MORRIS_PIECES);
	//EXPECT_TRUE(UnplacedW == SIX_MENS_MORRIS_PIECES);

	EXPECT_EQ(std::string(board), " RU:3 RC:1 >WU:4 WC:0\n" //Added two spaces between legend and board
		"R---------R---------R      0---1---2\n"
		"|         |         |      | 3-4-5 |\n"
		"|         |         |      6-7   8-9\n"
		"|    W----o----o    |      | A-B-C |\n"
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

TEST(SixMensMorrisBoardTest, TwoPieceGameOverTest) {
	// Needs to test that game over is correct when only two pieces left	
	CSixMensMorrisBoard board;
	board.Place('R', 0);
	board.Place('W', 2);
	board.Place('R', 1);
	board.Place('W', 3);
	board.Place('R', 4);
	board.Place('W', 9);
	board.Place('R', 6);
	board.Place('W', 10);
	board.Place('R', 7);
	board.Place('W', 12);
	board.Place('R', 11);
	board.Place('W', 13);
//////////////the placing phase//////////////////////
	board.CanMove('R', 5);
	board.Move('R', 5, 4);
	board.CanMove('W', 13);
	board.Move('W', 13, 15);
	board.CanRemove('W');
	board.Remove('W', 1);
	
	board.CanMove('R', 4);
	board.Move('R', 4, 5);
	board.CanMove('W', 15);
	board.Move('W', 15, 13);
	board.CanMove('R', 0);
	board.Move('R', 0, 1);
	board.CanMove('W', 15);
	board.Move('W', 15, 13);
	board.CanRemove('W');
	board.Remove('W', 1);
	
	board.CanMove('R', 4);
	board.Move('R', 4, 1);
	board.CanMove('W', 15);
	board.Move('W', 15, 13);
	board.CanMove('R', 1);
	board.Move('R', 1, 4);
	board.CanMove('W', 13);
	board.Move('W', 13, 15);
	board.CanRemove('W');
	board.Remove('W', 4);
	
	board.CanMove('R', 6);
	board.Move('R', 6, 0);
	board.CanMove('W', 15);
	board.Move('W', 15, 13);
	board.CanMove('R', 6);
	board.Move('R', 6, 0);
	board.CanMove('W', 13);
	board.Move('W', 13, 15);
	board.CanRemove('W');
	board.Remove('W', 0);

	std::cout<<board.ToString()<<std::endl;

	EXPECT_EQ(std::string(board), ">RU:0 RC:0 WU:0 WC:4\n" //Added two spaces between legend and board
		"o---------o---------W      0---1---2\n"
		"|         |         |      | 3-4-5 |\n"
		"|         |         |      6-7   8-9\n"
		"|    W----o----o    |      | A-B-C |\n"
		"|    |         |    |      D---E---F\n"
		"|    |         |    |        LEGEND\n"
		"o----R         o----W\n"
		"|    |         |    |\n"
		"|    |         |    |\n"
		"|    W----R----W    |\n"
		"|         |         |\n"
		"|         |         |\n"
		"o---------o---------W\n"
	);
	EXPECT_EQ(std::string(board), board.ToString());
	board.GameOver();
}

TEST(SixMensMorrisBoardTest, NoMoveGameOverTest) {
	// Needs to test that game over is correct when no movement allowed
	/*CSixMensMorrisBoard board;
	board.Place('R', 0);
	board.Place('W', 2);
	board.Place('R', 1);
	board.Place('W', 3);
	board.Place('R', 4);
	board.Place('W', 9);
	board.Place('R', 6);
	board.Place('W', 10);
	board.Place('R', 7);
	board.Place('W', 12);
	board.Place('R', 11);
	board.Place('W', 13);
	board.Move('R', 5, 4);
	board.Move('W', 13, 15);*/
}

TEST(SixMensMorrisBoardTest, BadParametersTest) {
	// Needs to test that correct return upon bad parameters
}

