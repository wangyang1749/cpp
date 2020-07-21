#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

using namespace std;

const int N = 15;

const char ChessBoardflag = ' ';

const char flag1 = 'o';

const char flag2 = 'X';

typedef struct Coordinate
{
	int x;
	int y;
} Coordinate;

class GoBang
{
public:
	GoBang() //初始化

	{

		InitChessBoard();
	}

	void Play() //开始

	{

		Coordinate Pos1;

		Coordinate Pos2;

		int n = 0;

		while (1)

		{

			int mode = ChoiceMode();

			while (1)

			{

				if (mode == 1) //电脑vs玩家

				{

					ComputerChess(Pos1, flag1);

					if (GetVictory(Pos1, 0, flag1) == 1)

						break;

					PlayChess(Pos2, 2, flag2);

					if (GetVictory(Pos2, 2, flag2))

						break;
				}

				else //玩家vs玩家

				{

					PlayChess(Pos1, 1, flag1);

					if (GetVictory(Pos1, 1, flag1))

						break;

					PlayChess(Pos2, 2, flag2);

					if (GetVictory(Pos2, 2, flag2))

						break;
				}
			}

			cout << "再来一局吧" << endl;

			cout << "y or n :";

			char c = 'y';

			cin >> c;

			if (c == 'n')

				break;
		}
	}

protected:
	int ChoiceMode() //选择模式

	{

		int i = 0;

		system("cls");

		InitChessBoard();

		cout << "/0、退出  1、电脑vs玩家  2、玩家vs玩家/" << endl;

		while (1)

		{

			cout << "请选择：";

			cin >> i;

			if (i == 0)

				exit(1);

			if (i == 1 || i == 2)

				return i;

			cout << "输入不正确，请输入1或2" << endl;
		}
	}

	void InitChessBoard() //初始化棋盘

	{

		for (int i = 0; i < N + 1; ++i)

		{

			for (int j = 0; j < N + 1; ++j)

			{

				_ChessBoard[i][j] = ChessBoardflag;
			}
		}
	}

	void PrintChessBoard() //打印棋盘

	{

		system("cls");

		for (int i = 0; i < N + 1; ++i)

		{

			for (int j = 0; j < N + 1; ++j)

			{

				if (i == 0)

				{

					if (j != 0)

						printf("%d  ", j);

					else

						printf("   ");
				}

				else if (j == 0)

					printf("%2d ", i);

				else

				{

					if (i < N + 1)

					{

						printf("%c |", _ChessBoard[i][j]);
					}
				}
			}

			cout << endl;

			cout << "   ";

			for (int m = 0; m < N; m++)

			{

				printf("—|");
			}

			cout << endl;
		}
	}

	void PlayChess(Coordinate &pos, int player, int flag) //玩家下棋

	{

		PrintChessBoard(); //打印棋盘

		while (1)

		{

			printf("玩家%d输入坐标：", player);

			cin >> pos.x >> pos.y;

			if (JudgeValue(pos) == 1) //判断坐标是否合法

				break;

			cout << "坐标不合法，重新输入" << endl;
		}

		_ChessBoard[pos.x][pos.y] = flag;
	}

	void ComputerChess(Coordinate &pos, char flag) //电脑下棋

	{

		PrintChessBoard(); //打印棋盘

		int x = 0;

		int y = 0;

		while (1)

		{

			x = (rand() % N) + 1;

			srand((unsigned int)time(NULL));

			y = (rand() % N) + 1;

			srand((unsigned int)time(NULL));

			if (_ChessBoard[x][y] == ChessBoardflag)

				break;
		}

		pos.x = x;

		pos.y = y;

		_ChessBoard[pos.x][pos.y] = flag;
	}

	int JudgeValue(const Coordinate &pos) //判断坐标是否合法

	{

		if (pos.x > 0 && pos.x <= N && pos.y > 0 && pos.y <= N)

		{

			if (_ChessBoard[pos.x][pos.y] == ChessBoardflag)

			{

				return 1;
			}
		}

		return 0;
	}

	int JudgeVictory(Coordinate pos, char flag) //判断是否有人获胜

	{

		int begin = 0;

		int end = 0;

		int begin1 = 0;

		int end1 = 0;
		//判断行是否满足条件
		(pos.y - 4) > 0 ? begin = (pos.y - 4) : begin = 1;

		(pos.y + 4) > N ? end = N : end = (pos.y + 4);

		for (int i = pos.x, j = begin; j + 4 <= end; j++)
		{

			if (_ChessBoard[i][j] == flag && _ChessBoard[i][j + 1] == flag &&

				_ChessBoard[i][j + 2] == flag && _ChessBoard[i][j + 3] == flag &&

				_ChessBoard[i][j + 4] == flag)

				return 1;
		}
		//判断列是否满足条件
		(pos.x - 4) > 0 ? begin = (pos.x - 4) : begin = 1;

		(pos.x + 4) > N ? end = N : end = (pos.x + 4);

		for (int j = pos.y, i = begin; i + 4 <= end; i++)

		{

			if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j] == flag &&

				_ChessBoard[i + 2][j] == flag && _ChessBoard[i + 3][j] == flag &&

				_ChessBoard[i + 4][j] == flag)

				return 1;
		}

		int len = 0;
		//判断主对角线是否满足条件
		pos.x > pos.y ? len = pos.y - 1 : len = pos.x - 1;
		if (len > 4)

			len = 4;

		begin = pos.x - len;

		begin1 = pos.y - len;

		pos.x > pos.y ? len = (N - pos.x) : len = (N - pos.y);

		if (len > 4)

			len = 4;

		end = pos.x + len;

		end1 = pos.y + len;

		for (int i = begin, j = begin1; (i + 4 <= end) && (j + 4 <= end1); ++i, ++j)

		{

			if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j + 1] == flag &&

				_ChessBoard[i + 2][j + 2] == flag && _ChessBoard[i + 3][j + 3] == flag &&

				_ChessBoard[i + 4][j + 4] == flag)

				return 1;
		}
		//判断副对角线是否满足条件
		(pos.x - 1) > (N - pos.y) ? len = (N - pos.y) : len = pos.x - 1;

		if (len > 4)

			len = 4;

		begin = pos.x - len;
		begin1 = pos.y + len;

		(N - pos.x) > (pos.y - 1) ? len = (pos.y - 1) : len = (N - pos.x);

		if (len > 4)

			len = 4;

		end = pos.x + len;

		end1 = pos.y - len;

		for (int i = begin, j = begin1; (i + 4 <= end) && (j - 4 >= end1); ++i, --j)

		{

			if (_ChessBoard[i][j] == flag && _ChessBoard[i + 1][j - 1] == flag &&

				_ChessBoard[i + 2][j - 2] == flag && _ChessBoard[i + 3][j - 3] == flag &&

				_ChessBoard[i + 4][j - 4] == flag)

				return 1;
		}

		for (int i = 1; i < N + 1; ++i) //判断棋盘是否下满
		{

			for (int j = 1; j < N + 1; ++j)

			{

				if (_ChessBoard[i][j] == ChessBoardflag)

					return 0; //没有下满
			}
		}

		return -1; //和棋
	}
	bool GetVictory(Coordinate &pos, int player, int flag) //对JudgeVictory
														   //的一层封装，得到具体那个玩家获胜
	{

		int n = JudgeVictory(pos, flag);

		if (n != 0) //有人获胜

		{

			PrintChessBoard();

			if (n == 1)
			{

				if (player == 0)

					printf("电脑获胜~\n");

				else

					printf("恭喜玩家%d获胜~\n", player);
			}

			else //没人获胜

				printf("可惜双方和棋~\n");

			return true;
		}

		return false;
	}

private:
	char _ChessBoard[N + 1][N + 1];
};
int main()
{

	GoBang a;
	a.Play();
	return 0;
}