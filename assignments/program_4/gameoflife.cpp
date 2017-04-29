#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

// #ifdef __cplusplus__
// #include <cstdlib>
// #else
// #include <stdlib.h>
// #endif

#include <time.h>

using namespace std;

class GameOfLife {
private:
	int **Board;
	int **Board2;
	int Rows;
	int Cols;
public:
	GameOfLife(string filename) {
		string line;
		char ch;
		ifstream fin;
		fin.open(filename);
		fin >> Rows >> Cols;
		InitBoardArray(Board);
		InitBoardArray(Board2);
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				fin.get(ch);
				if (ch == 10) {
					continue;
				}
				Board[i][j] = int(ch) - 48;
			}
		}
	}

	GameOfLife(int r, int c) {
		Rows = r;
		Cols = c;
		InitBoardArray(Board);
		InitBoardArray(Board2);
		PrintBoard();
	}

	void InitBoardArray(int **&b) {
		b = new int*[Rows];
		for (int i = 0; i < Rows; i++) {
			b[i] = new int[Cols];
		}
		ResetBoardArray(b);
	}

	void ResetBoardArray(int **&b) {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++) {
				b[i][j] = 0;
			}
		}
	}

	void PrintBoard() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++)
				cout << (Board[i][j] ? '#' : ' ');
			cout << endl;
		}
	}

	void RandomPopulate(int num) {
		int r = 0;
		int c = 0;
		for (int i = 0; i<num; i++) {
			r = rand() % Rows;
			c = rand() % Cols;
			Board[r][c] = 1;
		}
	}

	void SetCell(int r, int c, int val) {
		Board[r][c] = val;
	}

	void clear_screen(int lines) {
		for (int i = 0; i<lines; i++) {
			cout << endl;
		}
	}

	void Pause(int MilliSeconds)
	{
		clock_t t;
		t = clock();
		int sum = 0;

		while ((clock() - t) < MilliSeconds) {
			sum++;
		}

	}

	int CountNeighbors(int row, int col) {
		int neighbors = 0;
		if (Board[row][col] == 1) {
			neighbors--;
		}
		for (int i = row - 1; i <= row + 1; i++) {
			for (int j = col - 1; j <= col + 1; j++)
				neighbors += Board[(i + Rows) % Rows][(j + Cols) % Cols];
		}
		return neighbors;
	}

	void AddGens() {
		for (int i = 0; i < Rows; i++) {
			for (int j = 0; j < Cols; j++)
				Board[i][j] += Board2[i][j];
		}
		ResetBoardArray(Board2);
	}

	void AddGliderGun() {
		// Left Block
		SetCell(5, 1, 1);
		SetCell(5, 2, 1);
		SetCell(6, 1, 1);
		SetCell(6, 2, 1);
		//Left Gun
		SetCell(5, 11, 1);
		SetCell(6, 11, 1);
		SetCell(7, 11, 1);
		SetCell(4, 12, 1);
		SetCell(8, 12, 1);
		SetCell(3, 13, 1);
		SetCell(9, 13, 1);
		SetCell(3, 14, 1);
		SetCell(9, 14, 1);
		SetCell(6, 15, 1);
		SetCell(4, 16, 1);
		SetCell(8, 16, 1);
		SetCell(5, 17, 1);
		SetCell(6, 17, 1);
		SetCell(7, 17, 1);
		SetCell(6, 18, 1);
		//Right Gun
		SetCell(3, 21, 1);
		SetCell(4, 21, 1);
		SetCell(5, 21, 1);
		SetCell(3, 22, 1);
		SetCell(4, 22, 1);
		SetCell(5, 22, 1);
		SetCell(2, 23, 1);
		SetCell(6, 23, 1);
		SetCell(1, 25, 1);
		SetCell(2, 25, 1);
		SetCell(6, 25, 1);
		SetCell(7, 25, 1);
		// Right Block
		SetCell(3, 35, 1);
		SetCell(4, 35, 1);
		SetCell(3, 36, 1);
		SetCell(4, 35, 1);
	}

	void AddArmy() {
		SetCell(1, 1, 1);
		SetCell(1, 4, 1);
		SetCell(2, 5, 1);
		SetCell(3, 1, 1);
		SetCell(3, 5, 1);
		SetCell(4, 2, 1);
		SetCell(4, 3, 1);
		SetCell(4, 4, 1);
		SetCell(4, 5, 1);

		SetCell(8, 1, 1);
		SetCell(8, 4, 1);
		SetCell(9, 5, 1);
		SetCell(10, 1, 1);
		SetCell(10, 5, 1);
		SetCell(11, 2, 1);
		SetCell(11, 3, 1);
		SetCell(11, 4, 1);
		SetCell(11, 5, 1);

		SetCell(15, 1, 1);
		SetCell(15, 4, 1);
		SetCell(16, 5, 1);
		SetCell(17, 1, 1);
		SetCell(17, 5, 1);
		SetCell(18, 2, 1);
		SetCell(18, 3, 1);
		SetCell(18, 4, 1);
		SetCell(18, 5, 1);

		SetCell(22, 1, 1);
		SetCell(22, 4, 1);
		SetCell(23, 5, 1);
		SetCell(24, 1, 1);
		SetCell(24, 5, 1);
		SetCell(25, 2, 1);
		SetCell(25, 3, 1);
		SetCell(25, 4, 1);
		SetCell(25, 5, 1);
	}

	void AddGlider() {
		SetCell(7, 7, 1);
		SetCell(7, 8, 1);
		SetCell(7, 9, 1);
		SetCell(6, 9, 1);
		SetCell(5, 8, 1);
	}

	void Run(int generations = 99999) {
		int neighbors = 0;
		int g = 0;
		bool change;
		while (g < generations) {
			change = false;
			for (int i = 0; i < Rows; i++) {
				for (int j = 0; j < Cols; j++) {
					neighbors = CountNeighbors(i, j);
					if (Board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
						Board2[i][j] = -1;
						change = true;
					}
					if (Board[i][j] == 0 && neighbors == 3) {
						Board2[i][j] = 1;
						change = true;
					}
				}
			}

			AddGens();
			PrintBoard();
			//Pause(480);
			Pause(48);

			if (!change)
				break;

			change = false;

			system("cls");
			g++;
		}

	}
};

int main() {

	// hide cursor while printing
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

	//GameOfLife G(29, 60);
	GameOfLife G("gen_one.txt");
	
	//G.AddGlider();

	G.AddGliderGun();

	//G.AddArmy();

	G.Run();
	//G.PrintBoard();

	return 0;

}
