#include <iostream>
#include<vector>
#include <fstream>
#include <time.h>
#include<string>

using namespace std;


void newGame(int size) {
	char letter;
	int random;
	vector<char> availableLetters;
	string inputWord;
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		random = rand() % 26;
		letter = 'a' + random;
		availableLetters.push_back(letter);
	}
	for (int j = 0; j < size; j++) {
		cout << availableLetters[j] << " ";
	}
	cout << "\n" <<"Make a word:" << endl;
	cin >> inputWord;
	while (inputWord.length() > size) {
		cout << "Invalid word. Try again with: ";
		for (int j = 0; j < size; j++) {
			cout << availableLetters[j] << " ";
		}
		cin >> inputWord;
	}
	if (inputWord.length() <= size) {

	}


}
void wordExists() {
	fstream dictionary;
	dictionary.open("englishDictionary.txt");
}
int main() {
	cout << "SCRABBLE" << endl;

	cout << "1. START A NEW GAME" << endl;
	

	cout << "2. SETTINGS" << endl;
	

	cout << "3. INSERT A NEW WORD IN THE DICTIONARY" << endl;


	cout << "4. EXIT" << endl;
	

	int initialChoice;
	cout << "Select a number from the above:" << endl;
	cin >> initialChoice;
	while (initialChoice < 1 || initialChoice >4) {
		cout << "Please enter a number between 1 and 4:" << endl;
		cin >> initialChoice;
	}
	int size = 10;
	int rounds = 10;
	if (initialChoice == 1) {
			newGame(size);
	}
	return 0;
}