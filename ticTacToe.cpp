#include <iostream>

using namespace std;

char ticTacToe[] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
int input;




bool validateInput(int input) {


	if (ticTacToe[input] == 'X' || ticTacToe[input] == 'O') {
		return false;
	}


	return true;
}

void player1Turn() {
	input = -1;
	cout << "Player one choose a number" << endl;
	cin >> input;

	while (input <= 0 || input >= 10) {
		cout << "Error, out of bounds please choose a new number " << endl;
		cin >> input;
	}

	input--;
	
	if (validateInput(input) == false) {
		cout << "This spot is already taken " << endl;
		player1Turn();
	}

	


	ticTacToe[input] = 'X';
	

}

void player2Turn() {
	input = -1;
	cout << "Player two choose a number" << endl;
	cin >> input;
	
	while (input <= 0 || input >= 10) {
		cout << "Error, out of bounds please choose a new number " << endl;
		cin >> input;
	}
	
	input--;

	if (validateInput(input) == false) {
		cout << "This spot is already taken " << endl;
		player2Turn();
	}

	

	ticTacToe[input ] = 'O';


}




bool playerHasWon() {

	for (int i = 0; i <=6 ; i += 3) {
		if (ticTacToe[i] == 'X' && ticTacToe[i + 1] == 'X' && ticTacToe[i + 2] == 'X' || 
			ticTacToe[i] == 'O' && ticTacToe[i + 1] == 'O' && ticTacToe[i + 2] == 'O') {

			if (ticTacToe[i] == 'X') {
				cout << "X wins!" << endl;
			}

			if (ticTacToe[i] == 'O') {
				cout << "O wins!";
			}

			return true;
		}
	}

	for (int i = 0; i <= 2; i++) {
		if (ticTacToe[i] == 'X' && ticTacToe[i + 3] == 'X' && ticTacToe[i + 6] == 'X' ||
			ticTacToe[i] == 'O' && ticTacToe[i + 3] == 'O' && ticTacToe[i + 6] == 'O') {

			if (ticTacToe[i] == 'X') {
				cout << "X wins!" << endl;
			}

			if (ticTacToe[i] == 'O') {
				cout << "O wins!";
			}

			return true;
		}

		

	}

	if (ticTacToe[2] == ticTacToe[4] && ticTacToe[2] == ticTacToe[6]) {
		if (ticTacToe[2] == 'X') {
			cout << "X wins!" << endl;
		}

		if (ticTacToe[2] == 'O') {
			cout << "O wins!";
		}

		return true;

	}


	if (ticTacToe[0] == ticTacToe[4] && ticTacToe[0] == ticTacToe[8]) {
		if (ticTacToe[0] == 'X') {
			cout << "X wins!" << endl;
		}

		if (ticTacToe[0] == 'O') {
			cout << "O wins!";
		}
		return true;
	}



	return false;
}

bool playerWon() {
	if (playerHasWon()) {
		return true;
	}

	return false;
}

void drawBoard() {
	system("cls");
	cout << "Player one is X's, player to is O's" << endl;
	cout << "\n " << ticTacToe[0] << " | " << ticTacToe[1] << " | " << ticTacToe[2] << " " << endl;;
	cout << "-----------" << endl;
	cout << " " << ticTacToe[3] << " | " << ticTacToe[4] << " | " << ticTacToe[5] << " " << endl;
	cout << "-----------" << endl;
	cout << " " << ticTacToe[6] << " | " << ticTacToe[7] << " | " << ticTacToe[8] << " \n" << endl;

}



void updateGame() {
	int countTurns = 0;
	do {

		drawBoard();

		player1Turn();
		drawBoard();

		countTurns++;

		if (playerWon() == true) {
			break;
		}

		if (countTurns == 5) {
			cout << "No one wins!" << endl;
			break;
		}

		player2Turn();
		drawBoard();

		if (playerWon() == true) {
			break;
		}
		

		

	} while (playerWon() == false);
}

int main() {
	char x;
	while (true) {
		cout << "Press n to start and n to restart and e to exit" << endl;
		cin >> x;

		if (x == 'e') {
			cout << "Thank you for playing" << endl;
			break;
		}

		char start = '1';
		if (x == 'n') {
			for (int i = 0; i <= 8; i++) {
				ticTacToe[i] = start++;
			}

			updateGame();
		}

	}

}


