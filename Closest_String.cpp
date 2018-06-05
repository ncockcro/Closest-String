/*
Written by: Nicholas Cockcroft
Date: June 5, 2018

Description: Create a program which uses the Hamming Distance to find the closest string
string in a sequence of strings. For more information, follow the link to the original
reddit post that posted the problem: 
https://www.reddit.com/r/dailyprogrammer/comments/826coe/20180305_challenge_353_easy_closest_string/
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function for comparing two sequences
int compareSequences(string sequ1, string sequ2) {
	int count = 0;

	// Checking to ensure the user kept the same lenth for all sequences
	if (sequ1.length() != sequ2.length()) {
		cout << "Sequences are of different lengths, exiting program." << endl;
		exit(1);
	}
	for (size_t i = 0; i < sequ1.length(); i++) {
		if (sequ1[i] == sequ2[i]) {
			count++;
		}
	}
	return count;
}

int main() {

	// Initial variables
	int numOfSequences; // Number the user enters for how many sequences they WILL enter
	string userInput;
	vector<string> userSequences; // Data structure holding the different sequences the user types in

	// Getting the number of sequences which will be entered
	cout << "Type how the number of how many strings to be entered: ";
	cin >> numOfSequences;

	// Checking to ensure the user entered a number for how many sequences they will enter
	if (!cin) {
		cout << "User did not enter a number, exiting program." << endl;
		exit(1);
	}

	// Getting input of the sequences
	for (int i = 0; i < numOfSequences; i++) {
		cin >> userInput;
		userSequences.push_back(userInput);
	}


	// ******** Parsing Sequences Below **********

	string currentStringSequence; // Current sequence we are comparing with
	string comparisonStringSequence; // The comparison sequence that is being compared with the current sequence
	vector<int> countsOfSequences; // Holds the counts for each sequence using Hamming Distance
	int count;

	// The following for loops are used for comparing the sequences and retrieving all the counts
	// for how many times the same letter in a sequence was found in another sequence
	// The first for loop grabs the initial sequence that we want to compare with the others
	for (size_t i = 0; i < userSequences.size(); i++) {
		currentStringSequence = userSequences[i];
		count = 0;
		// The second for loop captures the sequence we want to compare with the current sequence
		for (size_t j = 0; j < userSequences.size(); j++) {
			comparisonStringSequence = userSequences[j];

			// Don't want to compare the same string so we skip
			if (currentStringSequence == comparisonStringSequence) {
				continue;
			}
			// Otherwise, we call the function to get the count of how many times a letter appeared in
			// both sequences and add it to the count
			else {
				count += compareSequences(currentStringSequence, comparisonStringSequence);
			}
		}
		// Once finished with the current sequence, we store the count and move on to the next one
		countsOfSequences.push_back(count);
	}

	// Here, we are finding which sequence had the highest count and storing that sequence as our final result
	int highestCount = -1;
	string highestSequence;
	for (size_t i = 0; i < countsOfSequences.size(); i++) {
		if (countsOfSequences[i] > highestCount) {
			highestCount = countsOfSequences[i];
			highestSequence = userSequences[i];
		}
	}

	// Finally, output the result to the user
	cout << "The closest string is: " << highestSequence << endl;

	return 0;
}