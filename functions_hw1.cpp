#include <iostream>
#include <algorithm>
#include <iomanip>
#include <windows.h>
using namespace std; 
#define e cout<<endl
// void minMax(int* ptr, int size); // #1
//void fillArray(int* ptr, int size); // #1, #2, #3 
//void displayArray(int* ptr, int size); // #1, #2, #3
// void negPosZero(int* ptr, int size); // #2
// void sortingArray(int* ptr, int size, int choice = 1);
//bool comp(int a, int b) { // #3
//	return a > b;
//} 

void show_cubes(int cube) {
	e;
	if (cube == 1) {
		cout << "   ";
		e;
		cout << " * ";
		e;
		cout << "   ";
		e;
	}
	if (cube == 2) {
		cout << "*   ";
		e;
		cout << "   *";
		e;
	}
	if (cube == 3) {
		cout << "*   ";
		e;
		cout << " * ";
		e;
		cout << "   *";
		e;
	}
	if (cube == 4) {
		cout << "* *";
		e;
		cout << "* *";
		e;
	}
	if (cube == 5) {
		cout << "* *";
		e;
		cout << " * ";
		e;
		cout << "* *";
		e;
	}
	if (cube == 6) {
		cout << "* * *";
		e;
		cout << "* * *";
		e;
	}
}

int bot_move() {
	cout << "Bot's move... ";
	Sleep(700);
	e;
	int cube = 1 + rand() % 6;
	cout << cube << '!';
	Sleep(700);
	show_cubes(cube);
	Sleep(700);
	return cube;
}
int user_move() {
	cout << "Your move... ";
	Sleep(700);
	e;
	int cube = 1 + rand() % 6;
	cout << cube << '!';
	Sleep(700);
	show_cubes(cube);
	Sleep(700);
	return cube;
}





void results(int user_score, int bot_score);

void process(int move) {
	e;
	int cube, bot_score = 0, user_score = 0;
	if (move == 0) {
		for (int i = 0; i < 5; ++i) {
			bot_score += bot_move();
			e;
			user_score += user_move();
			e;
			cout << "Bot's score now is " << bot_score << ". Yours is " << user_score << '.';
			Sleep(1200);
			e;
		}
	}
	if (move == 1) {
		for (int i = 0; i < 5; ++i) {
			user_score += user_move();
			e;
			bot_score += bot_move();
			e;
			cout << "Your score now is " << user_score << ". Bot's is " << bot_score << '.';
			Sleep(1200);
			e;
		}
	}
	results(user_score, bot_score);
}

void start() {
	cout << "Starting! Let's decide who moves first";
	Sleep(900);
	e;
	int random = rand() % 2;
	if (random == 0) {
		cout << "Bot starts first!";
		process(random);
	}
	else { cout << "You start first!"; process(random); }
}

void game(char choice, int bot_result=0, int user_result=0, string winner="none");

void menu(int bot_result=0, int user_result=0, string winner="none") {
	e;
	int menu_size = 40;
	for (int i = 0; i < menu_size; ++i) cout << '=';
	e;
	cout << setw(30) << "Hi! Welcome to Cube game" << endl;
	for (int i = 0; i < menu_size; ++i) cout << '=';
	e;
	cout << setw(25) << "MAIN MENU";
	e;
	cout << "Start the game - 'p'";
	e;
	cout << "Previous game score - 'w'";
	e;
	cout << "Quit - 'q'";
	char choice;
	e;
	cin >> choice;
	choice = tolower(choice);
	game(choice, bot_result, user_result, winner);

}

int main()
{
	srand(time(nullptr));
	menu(0, 0, "none");
	cout << "Quitting! ;(. We'll wait for you next time";
	return 0;
	// int size = 3; // #1
	// int size = 10; // #3
	/*cout << "Enter the size of the array: ";
	cin >> size;*/ //#2
	//int* ptr = new int[size]; // #1, #2, #3
	//fillArray(ptr, size); // #1, #2, #3
	//displayArray(ptr, size); // #1, #2, #3
	// sortingArray(ptr, size); // #3
	// negPosZero(ptr, size); //#2
	// minMax(ptr, size); #1

}

void game(char choice, int bot_result, int user_result, string winner) {
	if (choice == 'q' || choice == 'n') return;
	else if (choice == 'w') {
		if (winner == "none") {
			cout << "You haven't played yet! Wanna start a game? y/n";
			while (choice == 'n' || choice == 'q' || choice == 'y') {
				e;
				cin >> choice;
				choice = tolower(choice);
				if (choice == 'n' || choice == 'q') return;
				if (choice == 'y') game(choice);
				else cout << "I don't understand you :(. Try again?";
			}
		}
		else cout << "Your previous score was " << user_result << ". Bot's was " << bot_result << ". It's a "<<winner<<'.'; menu();
	}
	else if (choice == 'p' || choice == 'y') {
		start();
	}
	else {
		while (true) {
			cout << "I don't understand you :(. Wanna start a game? y/n";
			e;
			cin >> choice;
			choice = tolower(choice);
			game(choice);
		}
	}
}

void results(int user_score, int bot_score) {
	string winner;
	cout << "By the end of the game, the winner is... ";
	Sleep(1200);
	if (user_score > bot_score) { 
		cout << "You!!!";
		winner = "win";
	}
	else if (bot_score > user_score) { 
		cout << "Bot! Good luck next time.";
		winner = "loss";
	}
	else if (bot_score == user_score) {
		cout << "It's a tie!";
		winner = "tie";
	}
	e;
	cout << "Wanna go back to menu? y/n";
	char choice;
	while (choice != 'y' || choice != 'n' || choice != 'q') {
		e;
		cin >> choice;
		choice = tolower(choice);
		if (choice == 'y') menu(bot_score, user_score, winner);
		else if (choice == 'n' || choice == 'q') return;
		else cout << "I don't understand you, try again.";
		
	}
}
//void fillArray(int* ptr, int size) // #1, #2, #3
//{
//	for (int i = 0; i < size; ++i) {
//		ptr[i] = -5 + rand() % 11;
//	}
//
//}
//void displayArray(int* ptr, int size) // #1, #2, #3
//{
//	for (int i = 0; i < size; ++i) {
//		cout << ptr[i] << ' ';
//	}
//	cout << endl;
//}

//void sortingArray(int* ptr, int size, int choice) //#3
//{
//	if (choice == 0) {
//		sort(ptr, ptr + size);
//	}
//	else if (choice == 1) {
//		sort(ptr, ptr + size, comp);
//	}
//	else cout << "Error.";
//	displayArray(ptr, size);
//}

//void negPosZero(int* ptr, int size) // #2
//{
//	int neg = 0, pos = 0, zero = 0; 
//	for (int i = 0; i < size; ++i) {
//		if (ptr[i] < 0) neg++;
//		else if (ptr[i] > 0) pos++;
//		else zero++;
//	}
//	cout << "Negative nums: " << neg << ". Positive nums: " << pos << ". Zeros: " << zero;
//}

//void minMax(int* ptr, int size) // #1
//{
//	int min = 11, max=0;
//	for (int i = 0; i < size; ++i) {
//		if (ptr[i] >= max) max = ptr[i];
//		if (ptr[i] <= min) min = ptr[i];
//	}
//	cout << "The max num is " << max << ". The min num is " << min;
//}
