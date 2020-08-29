#include <iostream>
using namespace std;
//setting up boxBoard array
char boxBoard[10] = { 'o','1','2','3','4','5','6','7','8','9' };
int verifyGame();
void board();
int main()
{
	int competitor = 1, i, move;
	char spot;
	do
	{
		board();
		competitor = (competitor % 2) ? 1 : 2;
		//Asks player for move
		cout << "\nYour move? ";
		cin >> move;
		//Types of ’marks’ used in game (X and O)
		spot = (competitor == 1) ? 'X' : 'O';
		//Translating the numeric position (1-9) into a [0-based] 2D coordinate
		if (move == 1 && boxBoard[1] == '1')
			boxBoard[1] = spot;
		else if (move == 2 && boxBoard[2] == '2')
			boxBoard[2] = spot;
		else if (move == 3 && boxBoard[3] == '3')
			boxBoard[3] = spot;
		else if (move == 4 && boxBoard[4] == '4')
			boxBoard[4] = spot;
		else if (move == 5 && boxBoard[5] == '5')
			boxBoard[5] = spot;
		else if (move == 6 && boxBoard[6] == '6')
			boxBoard[6] = spot;
		else if (move == 7 && boxBoard[7] == '7')
			boxBoard[7] = spot;
		else if (move == 8 && boxBoard[8] == '8')
			boxBoard[8] = spot;
		else if (move == 9 && boxBoard[9] == '9')
			boxBoard[9] = spot;
		else
		{
			//If player chooses a wrong move...
			cout << "Wrong move! ";
			competitor--;
			cin.ignore();
			cin.get();
		}
		i = verifyGame();
		competitor++;
	}
	//How a ’win’ or ’tie’ is determined
	while (i == -1);
	board();
	if (i == 1)
		cout << "You win!\n";
	else
		cout << "Oh no, a tie!\n";
	cin.ignore();
	cin.get();
	return 0;
}
//Below are the combinations of ways a player can win game
int verifyGame()
{
	if (boxBoard[1] == boxBoard[2] && boxBoard[2] == boxBoard[3])
		return 1;
	else if (boxBoard[4] == boxBoard[5] && boxBoard[5] == boxBoard[6])
		return 1;
	else if (boxBoard[7] == boxBoard[8] && boxBoard[8] == boxBoard[9])
		return 1;
	else if (boxBoard[1] == boxBoard[4] && boxBoard[4] == boxBoard[7])
		return 1;
	else if (boxBoard[2] == boxBoard[5] && boxBoard[5] == boxBoard[8])
		return 1;
	else if (boxBoard[3] == boxBoard[6] && boxBoard[6] == boxBoard[9])
		return 1;
	else if (boxBoard[1] == boxBoard[5] && boxBoard[5] == boxBoard[9])
		return 1;
	else if (boxBoard[3] == boxBoard[5] && boxBoard[5] == boxBoard[7])
		return 1;
	else if (boxBoard[1] != '1' && boxBoard[2] != '2' && boxBoard[3] != '3'
		&& boxBoard[4] != '4' && boxBoard[5] != '5' && boxBoard[6] != '6'
		&& boxBoard[7] != '7' && boxBoard[8] != '8' && boxBoard[9] != '9')
		return 0;
	else
		return -1;
}
void board()
{
	//system("cls");
	cout << "\n***************************\n**\tX's or O's?      **\n*************** ***********\n";
	//cout << "competitor 1 (X) - competitor 2 (O)" << endl << endl;
	cout << endl;
	//cout << " | | " << endl;
	cout << " " << boxBoard[1] << " | " << boxBoard[2] << " | " << boxBoard[3
	] << endl;
	cout << "-----|-----|-----" << endl;
	//cout << " | | " << endl;
	cout << " " << boxBoard[4] << " | " << boxBoard[5] << " | " << boxBoard[6
	] << endl;
	cout << "-----|-----|-----" << endl;
	//cout << " | | " << endl;
	cout << " " << boxBoard[7] << " | " << boxBoard[8] << " | " << boxBoard[9
	] << endl;
	//cout << " | | " << endl << endl;
}