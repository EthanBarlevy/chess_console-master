#include "pch.h"
#include "CppUnitTest.h"
#include "chess.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ChessTest
{
	TEST_CLASS(ChessTest)
	{
	public:
		
		Game* game = new Game960();
		Game* normalGame = new Game();

		TEST_METHOD(Randomized)
		{
			bool same = true;
			for (int i = 0; i < sizeof(game->initial_board[0]); i++)
			{
				if (game->initial_board[0][i] == normalGame->initial_board[0][i])
				{
					same = false;
				}
			}
			//game->initial_board[0], normalGame->initial_board[0]
			Assert::IsTrue(same);
		}

		TEST_METHOD(BisopColors)
		{
			int count = 1;
			int bishop1 = -1;
			int bishop2 = -1;
			bool areSeprate = false;
			for each (auto piece in game->initial_board[0])
			{
				if (piece == 'B' || piece == 'b')
				{
					if (bishop1 == -1)
					{
						bishop1 = count;
						count++;
						continue;
					}
					else
					{
						bishop2 = count;
						break;
					}
				}
				count++;
			}

			if ((bishop1 % 2 == 0 && bishop2 % 2 == 1) || (bishop1 % 2 == 1 && bishop2 % 2 == 0))
			{
				areSeprate = true;
			}

			cout << bishop1 << " " << bishop2 << endl;

			Assert::IsTrue(areSeprate);
		}

		TEST_METHOD(KingBetweenRooks)
		{
			int rook1 = -1;
			int rook2 = -1;
			int king = -1;
			Assert::IsTrue((rook1 < king && rook2 > king) || (rook2 < king && rook1 > king));
		}

		TEST_METHOD(HasNoGaps)
		{
			int count = 0;
			for each (auto piece in game->initial_board[0])
			{
				if (piece == 'B' || piece == 'N' || piece == 'R' || piece == 'Q' || piece == 'K')
				{
					count++;
				}
			}
			Assert::AreEqual(count, 8);
		}

		// i think this one will pretty much allways be true because its a hassle to make a jagged array
		TEST_METHOD(IsCorrectLenth)
		{
			Assert::AreEqual((int)(sizeof(game->initial_board[0]) / sizeof(game->initial_board[0][0])), 8);
		}
	};
}
