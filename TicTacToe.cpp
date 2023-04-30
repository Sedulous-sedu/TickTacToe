#include <iostream> 
#include <windows.h>
using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);

int Game_num = 0, X_score = 0, O_score = 0, counter = 1;

int tictactoe_DualGame(void)
{
	int a = 0, b = 0, c = 0;
	char ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
	cout << '\n' << "The first to win 3 games is the winner" << string(4, '\n');
	cout << "  1 2 3" << endl;
	cout << "1 " << ch1 << " " << ch2 << " " << ch3 << endl;
	cout << "2 " << ch4 << " " << ch5 << " " << ch6 << endl; 
	cout << "3 " << ch7 << " " << ch8 << " " << ch9 << endl;
	
	while (true)
	{
		if (X_score == 3 || O_score == 3)
		{
			cout << "Thanks for playing" << string(2,'\n');
			break;
		}

		if (Game_num == counter)
		{
			cout << endl << "  1 2 3" << endl;
			cout << "1 " << ch1 << " " << ch2 << " " << ch3 << endl;
			cout << "2 " << ch4 << " " << ch5 << " " << ch6 << endl;
			cout << "3 " << ch7 << " " << ch8 << " " << ch9 << endl;

			++counter;
		}

		cout << endl << "Choose where to insert your 'X' mark, insert row then column: ";
		while (true)
		{
			SetConsoleTextAttribute(color, 12);
			cin >> a;
			SetConsoleTextAttribute(color, 7);
			cout << endl;

			switch (a)
			{
			case 11:
				if ((int)ch1 == 88 || (int)ch1 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'X' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch1 == 63)
				{
					ch1 = 88;
					break;
				}
			case 12:
				if ((int)ch2 == 88 || (int)ch2 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'X' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch2 == 63)
				{
					ch2 = 88;
					break;
				}
			case 13:
				if ((int)ch3 == 88 || (int)ch3 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'X' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch3 == 63)
				{
					ch3 = 88;
					break;
				}
			case 21:
				if ((int)ch4 == 88 || (int)ch4 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'X' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch4 == 63)
				{
					ch4 = 88;
					break;
				}
			case 22:
				if ((int)ch5 == 88 || (int)ch5 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'X' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch5 == 63)
				{
					ch5 = 88;
					break;
				}
			case 23:
				if ((int)ch6 == 88 || (int)ch6 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'X' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch6 == 63)
				{
					ch6 = 88;
					break;
				}
			case 31:
				if ((int)ch7 == 88 || (int)ch7 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'X' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch7 == 63)
				{
					ch7 = 88;
					break;
				}
			case 32:
				if ((int)ch8 == 88 || (int)ch8 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'X' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch8 == 63)
				{
					ch8 = 88;
					break;
				}
			case 33:
				if ((int)ch9 == 88 || (int)ch9 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'X' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch9 == 63)
				{
					ch9 = 88;
					break;
				}
			default:
				cout << "choose a valid row and column between 1 and 3, try again: ";
				continue;
			}
			break;
		}

		cout << "  1 2 3" << endl;
		cout << "1 " << ch1 << " " << ch2 << " " << ch3 << endl;
		cout << "2 " << ch4 << " " << ch5 << " " << ch6 << endl;
		cout << "3 " << ch7 << " " << ch8 << " " << ch9 << endl;

		c = ((int)ch1 + (int)ch2 + (int)ch3 + (int)ch4 + (int)ch5 + (int)ch6 + (int)ch7 + (int)ch8 + (int)ch9);
		if      ((int)ch1 == (int)ch2 && (int)ch3 == (int)ch2 && (int)ch2 == 88)
		{
			++Game_num;
			++X_score;
			cout << endl <<"'X' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch4 == (int)ch5 && (int)ch6 == (int)ch5 && (int)ch5 == 88)
		{
			++Game_num;
			++X_score;
			cout << endl <<"'X' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch7 == (int)ch8 && (int)ch9 == (int)ch8 && (int)ch8 == 88)
		{
			++Game_num;
			++X_score;
			cout << endl <<"'X' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch1 == (int)ch4 && (int)ch7 == (int)ch4 && (int)ch4 == 88)
		{
			++Game_num;
			++X_score;
			cout << endl <<"'X' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch2 == (int)ch5 && (int)ch8 == (int)ch5 && (int)ch5 == 88)
		{
			++Game_num;
			++X_score;
			cout << endl <<"'X' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch3 == (int)ch6 && (int)ch9 == (int)ch6 && (int)ch6 == 88)
		{
			++Game_num;
			++X_score;
			cout << endl <<"'X' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch1 == (int)ch5 && (int)ch9 == (int)ch5 && (int)ch5 == 88)
		{
			++Game_num;
			++X_score;
			cout << endl <<"'X' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch3 == (int)ch5 && (int)ch7 == (int)ch5 && (int)ch5 == 88)
		{
			++Game_num;
			++X_score;
			cout << endl <<"'X' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if (c == 756 || c == 747)
		{
			++Game_num;
			cout << endl <<"Tie!\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}

		cout << endl << "Choose where to insert your 'O' mark, insert row then column: ";
		while (true)
		{
			SetConsoleTextAttribute(color, 12);
			cin >> b;
			SetConsoleTextAttribute(color, 7);
			cout << endl;

			switch (b)
			{
			case 11:
				if ((int)ch1 == 88 || (int)ch1 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'O' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch1 == 63)
				{
					ch1 = 79;
					break;
				}
			case 12:
				if ((int)ch2 == 88 || (int)ch2 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'O' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch2 == 63)
				{
					ch2 = 79;
					break;
				}
			case 13:
				if ((int)ch3 == 88 || (int)ch3 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'O' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch3 == 63)
				{
					ch3 = 79;
					break;
				}
			case 21:
				if ((int)ch4 == 88 || (int)ch4 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'O' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch4 == 63)
				{
					ch4 = 79;
					break;
				}
			case 22:
				if ((int)ch5 == 88 || (int)ch5 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'O' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch5 == 63)
				{
					ch5 = 79;
					break;
				}
			case 23:
				if ((int)ch6 == 88 || (int)ch6 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'O' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch6 == 63)
				{
					ch6 = 79;
					break;
				}
			case 31:
				if ((int)ch7 == 88 || (int)ch7 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'O' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch7 == 63)
				{
					ch7 = 79;
					break;
				}
			case 32:
				if ((int)ch8 == 88 || (int)ch8 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'O' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch8 == 63)
				{
					ch8 = 79;
					break;
				}
			case 33:
				if ((int)ch9 == 88 || (int)ch9 == 79)
				{
					cout << "Already selected, try another position\n\nChoose where to insert your 'O' mark, insert row then column: ";
					continue;
				}
				else if ((int)ch9 == 63)
				{
					ch9 = 79;
					break;
				}
			default:
					cout << "choose a valid row and column between 1 and 3, try again: ";
					continue;
			}
			break;
		}

		cout << "  1 2 3" << endl;
		cout << "1 " << ch1 << " " << ch2 << " " << ch3 << endl;
		cout << "2 " << ch4 << " " << ch5 << " " << ch6 << endl;
		cout << "3 " << ch7 << " " << ch8 << " " << ch9 << endl;

		cout << endl;

		c = ((int)ch1 + (int)ch2 + (int)ch3 + (int)ch4 + (int)ch5 + (int)ch6 + (int)ch7 + (int)ch8 + (int)ch9);
		if      ((int)ch1 == (int)ch2 && (int)ch3 == (int)ch2 && (int)ch2 == 79)
		{
			++Game_num;
			++O_score;
			cout << endl <<"'O' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : "<< O_score <<"\n*****************";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch4 == (int)ch5 && (int)ch6 == (int)ch5 && (int)ch5 == 79)
		{
			++Game_num;
			++O_score;
			cout << endl <<"'O' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch7 == (int)ch8 && (int)ch9 == (int)ch8 && (int)ch8 == 79)
		{
			++Game_num;
			++O_score;
			cout << endl <<"'O' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch1 == (int)ch4 && (int)ch7 == (int)ch4 && (int)ch4 == 79)
		{
			++Game_num;
			++O_score;
			cout << endl << "'O' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch2 == (int)ch5 && (int)ch8 == (int)ch5 && (int)ch5 == 79)
		{
			++Game_num;
			++O_score;
			cout << endl <<"'O' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch3 == (int)ch6 && (int)ch9 == (int)ch6 && (int)ch6 == 79)
		{
			++Game_num;
			++O_score;
			cout << endl <<"'O' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch1 == (int)ch5 && (int)ch9 == (int)ch5 && (int)ch5 == 79)
		{
			++Game_num;
			++O_score;
			cout << endl <<"'O' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if ((int)ch3 == (int)ch5 && (int)ch7 == (int)ch5 && (int)ch5 == 79)
		{
			++Game_num;
			++O_score;
			cout << endl <<"'O' wins\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
		else if (c == 756 || c == 747)
		{
			++Game_num;
			cout << endl <<"Tie!\nGame " << Game_num << " is over\nX score : " << X_score << "\nO score : " << O_score << "\n*****************\n";
			a = 0, b = 0, c = 0;
			ch1 = 63, ch2 = 63, ch3 = 63, ch4 = 63, ch5 = 63, ch6 = 63, ch7 = 63, ch8 = 63, ch9 = 63;
			continue;
		}
	}

	return 0;
}
//int tictactoe_computer(void)
//{
//
//}

int main()
{
	int x = 0;
	cout << "Welcome to my game: Do you want to play against:\n\n1. Friend\n\n2. Computer" << string(2 , '\n');
	SetConsoleTextAttribute(color, 12);
	cin >> x;
	SetConsoleTextAttribute(color, 7);
	if (x == 1)
	{
		tictactoe_DualGame();
	}
	//else if (x == 2)
	//{
	//	int tictactoe_computer();
	//}
	else
	{
		cout << endl <<"You have'nt choose any of the choices.\nRestart the game and try again.\nThank you!";
	}

	return 0;
}