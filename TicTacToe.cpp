#include <iostream> 
#include <windows.h> // Windows-specific functions
#include <random> // Random number generation
#include <ctime> // Time functions
#pragma comment(lib, "winmm.lib") // Linking external library

using namespace std;

HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); // Handle for output color of console

//Initialization for all functions.
char Grid[4][4] = { {' ','1','2','3'},{'1','?','?','?'},{'2','?','?','?'},{'3','?','?','?'} }; // 4x4 2D array representing the game grid
int Game_num = 0, X_score = 0, O_score = 0, counter = 1; // Game counters and scores
int Xnum1 = 0, Xnum2 = 0, Onum1 = 0, Onum2 = 0, X_WinningIndicator = 1, O_WinningIndicator = 1, Timer = 2000; // Variables for checking win conditions

//Function Initializations.
void O_UserInput(void); // Function for user input
int RandomGen1(void); // Function for generating a random number
int RandomGen2(void); // Function for generating another random number
void O_Comp_Input(void); // Function for computer input

//General Functions for both computer and friend codes
//X O grid function.
void X_O_Grid(void) // Function for printing the grid
{
	system("CLS");
	for (int row = 0; row < 4; ++row)
	{
		for (int column = 0; column < 4; ++column)
		{
			cout << Grid[row][column] << " ";
		}
		cout << endl;
	}
	return;
}
//X User Input function.
void X_UserInput(void) // Function for taking input from user for X
{
	SetConsoleTextAttribute(color, 12); // Set console text color to red
	cin >> Xnum1 >> Xnum2; // Take user input for row and column
	SetConsoleTextAttribute(color, 7); // Set console text color back to default
	cout << endl;
	PlaySound(TEXT("mixkit-gate-latch-click-1924.wav"), NULL, SND_ASYNC); // Play sound effect

	for (int row = 1; row < 4; ++row) // Loop through the rows
	{
		for (int column = 1; column < 4; ++column) // Loop through the columns
		{
			if (Xnum1 == row && Xnum2 == column) // If user input matches current row and column
			{
				if (Grid[row][column] == 'O' || Grid[row][column] == 'X') // If the current position already has a mark
				{
					cout << "Already selected, try another position\nChoose where to insert your 'X' mark, insert row then column: ";
					return X_UserInput(); // Call the function again to prompt user for another input
				}
				else if (Grid[row][column] == '?') // If the current position is empty
				{
					Grid[row][column] = 'X'; // Set the current position to 'X'
					break; // Exit the loop
				}
			}
			if (Xnum1 > 3 || Xnum2 > 3 || Xnum1 == 0 || Xnum2 == 0) // If user input is out of bounds
			{
				cout << "choose a valid row and column between 1 and 3, try again: ";
				return X_UserInput(); // Call the function again to prompt user for another input
			}
		}
	}
	return; // Return to caller
}
//X player winning conditions function.

void X_Winning(void)
{
	// Initialize column and row to 1
	int column = 1;
	int row = 1;

	// Check all rows for X win
	while (row < 4)
	{
		// If there is an X in the current row and column
		if (Grid[row][column] == 'X')
		{
			// If this is the last column in the row, X has won
			if (column == 3)
			{
				// Play winning sound, update X score, and display win message
				PlaySound(TEXT("mixkit-small-win-2020.wav"), NULL, SND_ASYNC);
				++Game_num;
				++X_score;
				X_WinningIndicator = X_score;
				cout << "\n'X' wins\nGame " << Game_num << " is over\n'X' score: " << X_score << "\n'O' score : " << O_score << "\n*****************";
				Sleep(Timer);
				return;
			}
			// If there is an X in the current row but not in the last column, move to the next column
			++column;
			continue;
		}
		// If there is not an X in the current row and column, move to the next row
		else if (Grid[row][column] != 'X')
		{
			++row;
			column = 1;
			continue;
		}
	}

	// Check all columns for X win
	column = 1;
	row = 1;
	while (column < 4)
	{
		// If there is an X in the current row and column
		if (Grid[row][column] == 'X')
		{
			// If this is the last row in the column, X has won
			if (row == 3)
			{
				// Play winning sound, update X score, and display win message
				PlaySound(TEXT("mixkit-small-win-2020.wav"), NULL, SND_ASYNC);
				++Game_num;
				++X_score;
				X_WinningIndicator = X_score;
				cout << "\n'X' wins\nGame " << Game_num << " is over\n'X' score: " << X_score << "\n'O' score : " << O_score << "\n*****************";
				Sleep(Timer);
				return;
			}
			// If there is an X in the current column but not in the last row, move to the next row
			++row;
			continue;
		}
		// If there is not an X in the current row and column, move to the next column
		else if (Grid[row][column] != 'X')
		{
			++column;
			row = 1;
			continue;
		}
	}

	// Check diagonal for X win
	if (Grid[1][1] == Grid[2][2] && Grid[2][2] == Grid[3][3] && Grid[3][3] == 'X')
	{
		// Play winning sound, update X score, and display win message
		PlaySound(TEXT("mixkit-small-win-2020.wav"), NULL, SND_ASYNC);
		++Game_num;
		++X_score;
		X_WinningIndicator = X_score;
		cout << "\n'X' wins\nGame " << Game_num << " is over\n'X' score: " << X_score << "\n'O' score : " << O_score << "\n*****************";
		Sleep(Timer);
		return;
	}
	// Check if there is a diagonal win by 'X' from top-right to bottom-left
	else if (Grid[1][3] == Grid[2][2] && Grid[2][2] == Grid[3][1] && Grid[3][1] == 'X')
	{
		PlaySound(TEXT("mixkit-small-win-2020.wav"), NULL, SND_ASYNC);
		++Game_num;
		++X_score;
		X_WinningIndicator = X_score;
		cout << "\n'X' wins\nGame " << Game_num << " is over\n'X' score: " << X_score << "\n'O' score : " << O_score << "\n*****************";
		Sleep(Timer);
		return;
	}
	// Check if the game is a tie
	else if (int(Grid[1][1] + Grid[1][2] + Grid[1][3] + Grid[2][1] + Grid[2][2] + Grid[2][3] + Grid[3][1] + Grid[3][2] + Grid[3][3]) == 756)
	{
		++Game_num;
		X_WinningIndicator = X_score;
		cout << "\nTie!\nGame " << Game_num << " is over\n'X' score: " << X_score << "\n'O' score : " << O_score << "\n*****************";
		Sleep(Timer);
		return;
	}

	return;
}

//O player winning conditions function.
// This function checks if 'O' has won the game.
void O_Winning(void)
{
	int column = 1; // initialize column index to 1
	int row = 1; // initialize row index to 1
	while (row < 4) // loop through rows
	{
		if (Grid[row][column] == 'O') // check if cell contains 'O'
		{
			if (column == 3) // check if 'O' has occupied all cells in a row
			{
				PlaySound(TEXT("mixkit-small-win-2020.wav"), NULL, SND_ASYNC); // play sound effect
				++Game_num; // increment game number
				++O_score; // increment 'O' score
				O_WinningIndicator = O_score; // update winning indicator
				cout << "\n'O' wins\nGame " << Game_num << " is over\n'O' score: " << X_score << "\n'O' score : " << O_score << "\n*****************"; // print game over message
				Sleep(Timer);
				return; // exit function
			}
			++column; // move to next column
			continue; // go to next iteration of loop
		}
		else if (Grid[row][column] != 'O') // check if cell does not contain 'O'
		{
			++row; // move to next row
			column = 1; // reset column index to 1
			continue; // go to next iteration of loop
		}
	}

	column = 1; // reset column index to 1
	row = 1; // reset row index to 1
	while (column < 4) // loop through columns
	{
		if (Grid[row][column] == 'O') // check if cell contains 'O'
		{
			if (row == 3) // check if 'O' has occupied all cells in a column
			{
				PlaySound(TEXT("mixkit-small-win-2020.wav"), NULL, SND_ASYNC); // play sound effect
				++Game_num; // increment game number
				++O_score; // increment 'O' score
				O_WinningIndicator = O_score; // update winning indicator
				cout << "\n'O' wins\nGame " << Game_num << " is over\n'X' score: " << X_score << "\n'O' score : " << O_score << "\n*****************"; // print game over message
				Sleep(Timer);
				return; // exit function
			}
			++row; // move to next row
			continue; // go to next iteration of loop
		}
		else if (Grid[row][column] != 'O') // check if cell does not contain 'O'
		{
			++column; // move to next column
			row = 1; // reset row index to 1
			continue; // go to next iteration of loop
		}
	}

	// Checking if the diagonal from top-left to bottom-right has three 'O's in a row
	if (Grid[1][1] == Grid[2][2] && Grid[2][2] == Grid[3][3] && Grid[3][3] == 'O')
	{
		// If there are three 'O's in a row, play a sound indicating that 'O' has won the game
		PlaySound(TEXT("mixkit-small-win-2020.wav"), NULL, SND_ASYNC);
		++Game_num;
		++O_score;
		O_WinningIndicator = O_score;
		cout << "\n'O' wins\nGame " << Game_num << " is over\n'X' score: " << X_score << "\n'O' score : " << O_score << "\n*****************";
		Sleep(Timer);
		return;
	}
	// Checking if the diagonal from top-right to bottom-left has three 'O's in a row
	else if (Grid[1][3] == Grid[2][2] && Grid[2][2] == Grid[3][1] && Grid[3][1] == 'O')
	{
		// If there are three 'O's in a row, play a sound indicating that 'O' has won the game
		PlaySound(TEXT("mixkit-small-win-2020.wav"), NULL, SND_ASYNC);
		++Game_num;
		++O_score;
		O_WinningIndicator = O_score;
		cout << "\n'O' wins\nGame " << Game_num << " is over\n'X' score: " << X_score << "\n'O' score : " << O_score << "\n*****************";
		Sleep(Timer);
		return;
	}
	return;
}
//Countdown timer.
void Countdown_Timer(void)
{
	cout << endl;
	PlaySound(TEXT("mixkit-simple-game-countdown-921.wav"), NULL, SND_ASYNC);
	SetConsoleTextAttribute(color, 3);
	cout << "3\n";
	Sleep(1000);
	cout << "2\n";
	Sleep(1000);
	cout << "1\n";
	Sleep(1000);
	cout << "\nStart!";
	SetConsoleTextAttribute(color, 7);
	Sleep(1000);
	cout << endl;
	return;
}


//Main HumanVsHuman code and it's dedicated functions
//Multiplayer game function code.
int HumanVsHuman(void)
{
	Countdown_Timer();
	cout << '\n' << "The first to win 3 games is the winner" << string(4, '\n');
	X_O_Grid();

	while (true)
	{
		//final game Winning condition.
		if (X_score == 3 || O_score == 3)
		{
			cout << "\n\nThanks for playing" << string(2, '\n');
			Sleep(2000);
			break;
		}

		//Grid resetter after each game.
		if (Game_num == counter)
		{
			Grid[0][0] = ' ', Grid[0][1] = '1', Grid[0][2] = '2', Grid[0][3] = '3',
				Grid[1][0] = '1', Grid[1][1] = '?', Grid[1][2] = '?', Grid[1][3] = '?',
				Grid[2][0] = '2', Grid[2][1] = '?', Grid[2][2] = '?', Grid[2][3] = '?',
				Grid[3][0] = '3', Grid[3][1] = '?', Grid[3][2] = '?', Grid[3][3] = '?';
			cout << endl << endl;
			X_O_Grid();
			++counter;
		}

		//X player section.
		cout << endl << "Choose where to insert your 'X' mark, insert row then column: ";

		X_UserInput();

		X_O_Grid();

		X_Winning();
		if (X_WinningIndicator == X_score)
		{
			++X_WinningIndicator;
			continue;
		}


		//O player section.
		cout << endl << "Choose where to insert your 'O' mark, insert row then column: ";

		O_UserInput();

		X_O_Grid();

		O_Winning();
		if (O_WinningIndicator == O_score)
		{
			++O_WinningIndicator;
			continue;
		}
	}

	return 0;
}
//O User Input function.
void O_UserInput(void)
{
	SetConsoleTextAttribute(color, 12);
	cin >> Onum1 >> Onum2;
	SetConsoleTextAttribute(color, 7);
	cout << endl;
	PlaySound(TEXT("mixkit-interface-click-1126.wav"), NULL, SND_ASYNC);

	for (int row = 1; row < 4; ++row)
	{
		for (int column = 1; column < 4; ++column)
		{
			if (Onum1 == row && Onum2 == column)
			{
				if (Grid[row][column] == 'O' || Grid[row][column] == 'X')
				{
					cout << "Already selected, try another position\nChoose where to insert your 'O' mark, insert row then column: ";
					return O_UserInput();
				}
				else if (Grid[row][column] == '?')
				{
					Grid[row][column] = 'O';
					break;
				}
			}
			if (Onum1 > 3 || Onum2 > 3 || Onum1 == 0 || Onum2 == 0)
			{
				cout << "choose a valid row and column between 1 and 3, try again: ";
				return O_UserInput();
			}
		}
	}

	return;
}

//Main HumanVsComputer code and it's dedicated functions
//Computer game function code.
int HumanVsComputer(void)
{
	Countdown_Timer();
	cout << '\n' << "The first to win 3 games is the winner" << string(4, '\n');
	X_O_Grid();

	while (true)
	{
		//final game Winning condition.
		if (X_score == 3 || O_score == 3)
		{
			cout << "\n\nThanks for playing" << string(2, '\n');
			Sleep(2000);
			break;
		}

		//Grid resetter after each game.
		if (Game_num == counter)
		{
			Grid[0][0] = ' ', Grid[0][1] = '1', Grid[0][2] = '2', Grid[0][3] = '3',
				Grid[1][0] = '1', Grid[1][1] = '?', Grid[1][2] = '?', Grid[1][3] = '?',
				Grid[2][0] = '2', Grid[2][1] = '?', Grid[2][2] = '?', Grid[2][3] = '?',
				Grid[3][0] = '3', Grid[3][1] = '?', Grid[3][2] = '?', Grid[3][3] = '?';
			cout << endl << endl;
			X_O_Grid();
			++counter;
		}

		//X player section.
		cout << endl << "Choose where to insert your 'X' mark, insert row then column: ";

		X_UserInput();

		X_O_Grid();

		Sleep(700);

		X_Winning();
		if (X_WinningIndicator == X_score)
		{
			++X_WinningIndicator;
			continue;
		}


		//O player section
		O_Comp_Input();

		cout << endl << "Computer chose " << Onum1 << " " << Onum2 << endl << endl;

		X_O_Grid();

		Sleep(700);

		O_Winning();
		if (O_WinningIndicator == O_score)
		{
			++O_WinningIndicator;
			continue;
		}
	}

	return 0;
}
//Randome number generators.
int RandomGen1(void)
{
	random_device rd1;
	uniform_int_distribution<int> dist(0, 4);
	return dist(rd1);
}
int RandomGen2(void)
{
	random_device rd2;
	uniform_int_distribution<int> dist(0, 4);
	return dist(rd2);
}

//O User Input function.
// This function generates random row and column numbers for the computer player's move,
// and checks if the generated cell is already occupied or outside the board,
// before marking it as 'O' in the grid. If the cell is occupied or outside the board,
// the function recursively calls itself until a valid move is generated.
void O_Comp_Input(void)
{
	// Generate random row and column numbers
	Onum1 = RandomGen1();
	Onum2 = RandomGen2();
	// Play a sound to indicate the computer player's move
	PlaySound(TEXT("mixkit-interface-click-1126.wav"), NULL, SND_ASYNC);

	// Check if the generated cell is already occupied or outside the board
	for (int row = 1; row < 4; ++row)
	{
		for (int column = 1; column < 4; ++column)
		{
			if (Onum1 == row && Onum2 == column)
			{
				if (Grid[row][column] == 'O' || Grid[row][column] == 'X')
				{
					// If the cell is already occupied, recursively call the function to generate a new move
					return O_Comp_Input();
				}
				else if (Grid[row][column] == '?')
				{
					// If the cell is empty, mark it as 'O' in the grid and exit the loop
					Grid[row][column] = 'O';
					break;
				}
			}
			// If the generated cell is outside the board, recursively call the function to generate a new move
			if (Onum1 > 3 || Onum2 > 3 || Onum1 == 0 || Onum2 == 0)
			{
				return O_Comp_Input();
			}
		}
	}
	return;
}


//main function.
int main()
{
	// Initialize the game mode to 0
	int GameMode = 0;

	cout << "Welcome to my game: Do you want to play against:\n\n1. Friend\n\n2. Computer" << string(2, '\n');

	// Change the console text color to red to indicate input prompt
	SetConsoleTextAttribute(color, 12);
	cin >> GameMode;

	// Reset the console text color to white
	SetConsoleTextAttribute(color, 7);

	if (GameMode == 1)
	{
		HumanVsHuman();
	}
	else if (GameMode == 2)
	{
		HumanVsComputer();
	}
	else
	{
		cout << endl << "You haven't chosen any of the choices.\nRestart the game and try again.\nThank you!";
	}

	system("pause>0");
	return 0;
}
