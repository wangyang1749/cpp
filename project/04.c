#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//建立游戏菜单1
int menu1() {
	printf("****************\n");
	printf("***1.开始游戏***\n");
	printf("*****五子棋*****\n");
	printf("***2.结束游戏***\n");
	printf("****************\n");
	printf("请输入您的选择：\n");
	int choice1 = 0;
	scanf("%d", &choice1);
	return choice1;
}
//建立游戏菜单2
int menu2() {
	printf("****************\n");
	printf("***1.人机对战***\n");
	printf("***2.玩家VS玩家*\n");
	printf("***3.返回*******\n");
	printf("****************\n");
	printf("请输入您的选择：\n");
	int choice2 = 0;
	scanf("%d", &choice2);
	return choice2;
}
#define MAX_ROW 5
#define MAX_COL 5
char chess_board[MAX_ROW][MAX_COL] = { 0 };
//1.初始化棋盘   
void Init() {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chess_board[row][col] = ' ';
		}
	}
	//设置随机种子
	srand((unsigned int)time(0));
}
//如果棋盘满，返回1 否则返回0
int IsFull() {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			if (chess_board[row][col] == ' ') {
				//棋盘未满
				return 0;
			}
		}
	}
	return 1;
}
//打印五子棋盘
void Print() {
	for (int row = 0; row < MAX_ROW; row++) {
		printf("| %c | %c | %c | %c | %c |\n", chess_board[row][0],
			chess_board[row][1], chess_board[row][2], chess_board[row][3], chess_board[row][4]);
		if (row != MAX_ROW - 1) {
			printf("|---|---|---|---|---| \n");
		}
	}
	//system("pause");
}
//2.玩家落子
void PlayerMove() {
	printf("玩家落子！\n");
	while (1) {
		printf("请输入落子位置的坐标(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//检查坐标是否合法?
		if (row < 0 || row >= MAX_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("您输入的坐标不合法！请重新输入!\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("您要下的地方已经被占用！请重新输入!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	printf("玩家落子完毕！\n");

}
//3.判断胜负
//返回值表示胜利者是谁
//x表示玩家胜  o表示电脑胜 r表示和棋 ' '表示未分胜负 ‘y'表示玩家2获胜
char  CheckWiner() {
	//检测所有行是否连成一条线 所有列是否连成一条线  对角线是否连成一条线
	for (int row = 0; row < MAX_ROW; row++) {
		if (chess_board[row][0] == chess_board[row][1] &&
			chess_board[row][0] == chess_board[row][2] && chess_board[row][0] == chess_board[row][3]
			&& chess_board[row][0] == chess_board[row][4]) {
			return chess_board[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (chess_board[0][col] == chess_board[1][col] &&
			chess_board[0][col] == chess_board[2][col] && chess_board[0][col] == chess_board[3][col]
			&& chess_board[0][col] == chess_board[4][col]) {
			return chess_board[0][col];
		}
	}
	if (chess_board[0][0] == chess_board[1][1] &&
		chess_board[0][0] == chess_board[2][2] && chess_board[0][0] == chess_board[3][3] & chess_board[0][0] == chess_board[4][4]) {
		return chess_board[0][0];
	}
	if (chess_board[0][4] == chess_board[1][3] &&
		chess_board[0][4] == chess_board[2][2] && chess_board[0][4] == chess_board[3][1]
		&& chess_board[0][4] == chess_board[4][0]) {
		return chess_board[0][4];
	}
	//和棋  棋盘满并且未分出胜负
	if (IsFull()) {
		return 'r';
	}
	return ' ';
}
//4.电脑落子
void ComputerMove() {
	printf("电脑落子！\n");
	while (1) {
		int row = rand() % 5;
		int col = rand() % 5;
		if (chess_board[row][col] != ' ') {
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	printf("电脑落子完毕！\n");

}
//5.玩家2落子
void PlayerMove2() {
	printf("玩家2落子！\n");
	while (1) {
		printf("请输入落子位置的坐标(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//检查坐标是否合法?
		if (row < 0 || row >= MAX_ROW
			|| col < 0 || col >= MAX_COL) {
			printf("您输入的坐标不合法！请重新输入!\n");
			continue;
		}
		if (chess_board[row][col] != ' ') {
			printf("您要下的地方已经被占用！请重新输入!\n");
			continue;
		}
		chess_board[row][col] = 'y';
		break;
	}
	printf("玩家落子完毕！\n");

}
//主游戏1
void game1() {
	Init();
	char winner = ' ';
	while (1) {
		Print();
		PlayerMove();
		winner = CheckWiner();
		if (winner != ' ') {
			//胜负已分
			break;
		}
		ComputerMove();
		winner = CheckWiner();
		if (winner != ' ') {
			break;
		}
	}
	Print();
	if (winner == 'x') {
		printf("您赢啦！\n");
	}
	else if (winner == 'o') {
		printf("您败了！\n");
	}
	else if (winner == 'r') {
		printf("您和电脑一样菜！\n");
	}
	else {
		printf("代码bug啦！\n");
	}
}
//主游戏2
void game2() {
	Init();
	char winner = ' ';
	while (1) {
		Print();
		PlayerMove();
		winner = CheckWiner();
		if (winner != ' ') {
			//胜负已分
			break;
		}
		Print();
		PlayerMove2();
		winner = CheckWiner();
		if (winner != ' ') {
			break;
		}
	}
	Print();
	if (winner == 'x') {
		printf("玩家获胜！\n");
	}
	else if (winner == 'y') {
		printf("玩家2获胜！\n");
	}
	else if (winner == 'r') {
		printf("平局！\n");
	}
	else {
		printf("代码bug啦！\n");
	}
}
//主函数
int main() {
	while (1) {
		int choice1 = menu1();
		if (choice1 == 1) {
			while (1) {
				int choice2 = menu2();
				if (choice2 == 1) {
					game1();
				}
				else if (choice2 == 2) {
					game2();
				}
				else if (choice2 == 3) {
					int choice1 = menu1();
					if (choice1 == 2) {
						printf("欢迎下次来玩！\n");
						break;
					}
				}
				else {
					printf("您的选择有误!\n");
				}
			}
			break;
		}
		else if (choice1 == 2) {
			printf("欢迎下次来玩！\n");
			break;
		}
		else {
			printf("您的输入有误！\n");
		}
	}
	return 0;
	system("pause");
}
