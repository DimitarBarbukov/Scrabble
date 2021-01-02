#include <iostream>
#include<vector>
#include <fstream>
#include <time.h>
#include<string>
#include < stdlib.h >

using namespace std;
void newGame(int numOfLetters) {
	char letter;
	int random;
	vector<char> availableLetters;
	string inputWord;
	srand(time(NULL));
	for (int i = 0; i < numOfLetters; i++) {
		random = rand() % 26;
		letter = 'a' + random;
		availableLetters.push_back(letter);
	}
	for (int j = 0; j < numOfLetters; j++) {
		cout << availableLetters[j] << " ";
	}
	cout << "\n" << "Make a word:" << endl;
	cin >> inputWord;
	while (inputWord.length() > numOfLetters) {
		cout << "Invalid word. Try again with: ";
		for (int j = 0; j < numOfLetters; j++) {
			cout << availableLetters[j] << " ";
		}
		cin >> inputWord;
	}
	int compatible = 0;
	if (inputWord.length() <= numOfLetters) {
		for (int p = 0; p < inputWord.length(); p++) {
			for (int r = 0; r < numOfLetters; r++) {
				if (availableLetters[r] == inputWord[p]) {
					compatible = 0;
					break;
				}
				else {
					compatible = 1;
					continue;
				}
			}
			if (compatible != 0) {
				cout << "Invalid word. Try again with: ";
				for (int j = 0; j < numOfLetters; j++) {
					cout << availableLetters[j] << " ";
				}
				cin >> inputWord;
				p = -1;
			}
		}
	}


}

int InsertANewWord(string newWord) {

	ofstream Dictionary;
	Dictionary.open("englishDictionary.txt");
	Dictionary << newWord << endl;
	Dictionary.close();
	return 0;

}
int main() {
	int initialChoice;
	int numOfLetters = 10;
	int rounds = 10;
	int optionInSettings;
	int returnButton;
	string newWord;

	cout << "SCRABBLE" << endl;
	for (; ; ) {
		cout << "1. START A NEW GAME" << endl;
		cout << "2. SETTINGS" << endl;
		cout << "3. INSERT A NEW WORD IN THE DICTIONARY" << endl;
		cout << "4. EXIT" << endl;
		cout << "Select a number from the above:" << endl;
		cin >> initialChoice;
		while (initialChoice < 1 || initialChoice >4) {
			cout << "Please enter a number between 1 and 4:" << endl;
			cin >> initialChoice;
		}
		if (initialChoice == 4) {
			break;
		}
		if (initialChoice == 2) {
			cout << "1. Change the number of given letters" << endl;
			cout << "2. Change the number of rounds" << endl;
			cout << "0. Back" << endl;
			cout << "\n" << "Select the number of the option you want: " << endl;
			cin >> optionInSettings;
			while (optionInSettings < 0 || optionInSettings > 2) {
				cout << "Please enter a number between 0 and 2:" << endl;
				cin >> optionInSettings;
			}
			if (optionInSettings == 1) {
				cout << "How many letters do you wish to have?" << endl;
				cin >> numOfLetters;
				while (numOfLetters < 3 || numOfLetters > 100) {
					cout << "Please enter a number between 3 and 100" << endl;
					cin >> numOfLetters;
				}
				cout << "Press any key to return to the menu" << endl;
				cin >> returnButton;
			}
			if (optionInSettings == 2) {
				cout << "How many rounds do you wish to have? " << endl;
				cin >> rounds;
				while (rounds < 1 || rounds > 20) {
					cout << "Please enter a number between 1 and 20" << endl;
					cin >> rounds;
				}
				cout << "Press any key to return to the menu" << endl;
				cin >> returnButton;
			}
			if (optionInSettings == 0) {
				continue;
			}
		}
		if (initialChoice == 3) {
			cout << "Enter a word" << endl;
			cin >> newWord;
			InsertANewWord(newWord);
			cout<< "Press any key to return to the menu" << endl;
			cin >> returnButton;
		}
		if (initialChoice == 1) {
			break;
		}
	}
	if (initialChoice == 4) {
		exit(0);
	}
	if (initialChoice == 1) {
		newGame(numOfLetters);
	}




	return 0;
}