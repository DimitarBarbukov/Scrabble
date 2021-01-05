
/*
*
* Solution to course project # 8
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2020/2021
*
* @author Dimitar Barbukov
* @idnumber 62637
* @compiler VC
*
* Scrabble
*
*/
#include <iostream>
#include<vector>
#include <fstream>
#include <time.h>
#include<string>
#include < stdlib.h >

using namespace std;

void GamePlay(int numOfLetters, int rounds)
{
	int score = 0; 
	for (int d = 0; d < rounds; d++) {
		int whichRound = d + 1;                      //counts the rounds based on the for-loop with a variable "d"
		cout << "\n" << "ROUND " << whichRound << endl;

		char letter;
		int random;
		int numberOfLettersInTheAlphabet = 26;
		vector<char> availableLetters;
		string inputWord;
		srand(time(NULL));
		for (int i = 0; i < numOfLetters; i++) {                   // for-loop for generating n-number of random letters
			random = rand() % numberOfLettersInTheAlphabet;               
			letter = 'a' + random;
			availableLetters.push_back(letter);                   // puts the letters in a vector
		}
		for (int j = 0; j < numOfLetters; j++) {
			cout << availableLetters[j] << " ";                  // prints them
		}
		cout << "\n" << "Make a word:" << endl;
		cin >> inputWord;
		int repeatedInput = 1;             // by default every letter in the input word appears at least once                     
		int repeatedLetters = 1;           // same as repeatedInput. If the user enters a letter which is not available for use, the code has another variable to check for that - noLetter
		int tooManyLetters = 4;            // if the user repeats a given letter more times than it appears, this variable will activate the needed mechanism
		int noLetter = 0;
		for (; ;)                  // a loop, in case the input word passes all the checks for compatibility but not the dictionary check
		{

			for (int f = 0; f < inputWord.length(); f++) {
				vector<char> input(inputWord.begin(), inputWord.end());
				repeatedInput = 1;
				repeatedLetters = 1;
				tooManyLetters = 4;
				for (int s = f; s < inputWord.length(); s++) {
					if (f != s) {
						if (input[f] == input[s]) {                           // checks whether a letter in the input word is repeated and how many times
							repeatedInput = repeatedInput + 1;
						}

					}
				}
				for (int r = 0; r < numOfLetters; r++)
				{
					if (input[f] == availableLetters[r])                    // looks for a match between the input and available letters
					{
						noLetter = 0;
						for (int u = r; u < numOfLetters; u++)
						{
							if (r != u)
							{
								if (availableLetters[r] == availableLetters[u]) {       // checks whether an available letter is repeated and how many times
									repeatedLetters = repeatedLetters + 1; 
								}
							}
						}
						if (repeatedInput > repeatedLetters) {
							tooManyLetters = 1;                // first mechanism for spotting invalid input : too many repeats of a letter in the input word
							break;
						}
						else {
							repeatedInput = 1;
							repeatedLetters = 1;
							break;
						}
					}
					else {
						noLetter = 1;      // if no match with the available letters is found, the "invalid mechanism" will be triggered
					}
				}
				if (tooManyLetters == 1 || noLetter == 1) {             // if-case invalid input mechanism
					cout << "Invalid word. Please try again with:";
					for (int j = 0; j < numOfLetters; j++) {
						cout << availableLetters[j] << " ";
					}
					cin >> inputWord;
					f = -1;
				}
				
			}
			int wordExists = 0;
			int matches = 0;
			ifstream Dictionary;
			Dictionary.open("englishDictionary.txt", ios::in);         // opening the dictionary file
			string line;           
			if (!Dictionary) {
				cout << "problem" << endl;
			}
			else
			{
				while (getline(Dictionary, line))    // makes every line in the dictionary file a string word      
				{
					vector<char> input(inputWord.begin(), inputWord.end());
					vector<char>wordInDictionary(line.begin(), line.end());     // changes the string into a vector
					if (inputWord.length() == line.length()) {                  // comparison
						for (int i = 0; i < inputWord.length(); i++) {
							if (input[i] == wordInDictionary[i])
							{
								matches = 1;
								continue;
							}
							else {
								matches = 0;        // if no matches are found, that means that the input word does not exist in the dictionary, thus triggering another input and a new begining of the cycle
								break;
							}
						}
						if (matches == 1) {
							wordExists = 1;
							break;
						}
					}
				}
				if (wordExists == 1)
				{
					score = score + inputWord.length();                   // adds the length of the current word to the previous score
					cout << "Your score is " << score << endl;
					break;
				}
				else {
					cout << "Invalid word. Please try again with:";
					for (int j = 0; j < numOfLetters; j++) {
						cout << availableLetters[j] << " ";
					}
					cin >> inputWord;
					vector<char> input(inputWord.begin(), inputWord.end());
					continue;         //loops again;
				}
				

			}
		}
	}
	cout << "The game ended." << endl;
	
}

int main() {
	int initialChoice;
	int numOfLetters = 10;
	int rounds = 10;
	int optionInSettings;
	char returnButton;
	string newWord;
	cout << "SCRABBLE" << endl;
	for (; ;) 
	{
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
		if (initialChoice == 4)
		{
			break;
		}
		if (initialChoice == 2)
		{
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
				cout << "Enter the amount of letters you wish to have:" << endl;
				cin >> numOfLetters;
				while (numOfLetters < 3 || numOfLetters > 100) {
					cout << "Please enter a number between 3 and 100" << endl;
					cin >> numOfLetters;
				}
				cout << "Press any key to return to the menu" << endl;
				cin >> returnButton;
			}
			if (optionInSettings == 2) {
				cout << "Enter the amount of rounds you wish to have: " << endl;
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
		if (initialChoice == 3)
		{
			cout << "Enter a word" << endl;
			cin >> newWord;
			ofstream Dictionary;
			Dictionary.open("englishDictionary.txt", ios::app);
			Dictionary << newWord << endl;
			Dictionary.close();
			cout << "Press any key to return to the menu" << endl;
			cin >> returnButton;
		}
		if (initialChoice == 1) 
		{
			break;
		}
	}
	if (initialChoice == 4) {
		exit(0);
	}
	if (initialChoice == 1)
	{
		GamePlay(numOfLetters, rounds);

	}

	return 0; 
}