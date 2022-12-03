#include <iostream>
#include <fstream>
#include <unordered_map>
#include <array>

const std::string dayMessage = "Day 2";
const std::string inputFilename = "input.txt";
// PART 1 //

// Maps the whole line entry to a point value dictating win/lose/draw of the round from player prospective
const std::unordered_map<std::string, int> gameResults = {
	{"A X", 3},
	{"A Y", 6},
	{"A Z", 0},
	{"B X", 0},
	{"B Y", 3},
	{"B Z", 6},
	{"C X", 6},
	{"C Y", 0},
	{"C Z", 3}
};
// Calculates the assigned point value of the player's choice; X = 1, Y = 2, Z = 3
int getPlayerLetterValue(char letter) {
	return (letter - 'X') + 1;
}

int partOne() {
	// Create a text string, which is used to output the text file
	std::string line;
	// Create file stream instance to read file
	std::ifstream file(inputFilename);

	int playerScore = 0;
	// Check line value in pre-built map and add it to the player's choice value
	while (std::getline(file, line)) {
		playerScore += gameResults.at(line) + getPlayerLetterValue(line.back());
	}
	file.close();

	return playerScore;
}

// PART 2 //
// Maps the whole line value to the resulting player choice to achieve the X/Y/Z result
// X = lose, Y = draw, Z = win
const std::unordered_map<std::string, char> playerChoiceMapping = {
	{"A X", 'Z'},
	{"A Y", 'X'},
	{"A Z", 'Y'},
	{"B X", 'X'},
	{"B Y", 'Y'},
	{"B Z", 'Z'},
	{"C X", 'Y'},
	{"C Y", 'Z'},
	{"C Z", 'X'}
};
// Maps the letter signifying round result to the point value from player's perspective
// X = 0, Y = 3, Z = 6
const std::array<int, 3> resultLetterValue = {0, 3, 6};

int partTwo() {
	// Create a text string, which is used to output the text file
	std::string line;
	// Create file stream instance to read file
	std::ifstream file(inputFilename);

	int playerScore = 0;
	// Last char of line maps directly to round score, add that to resolved value of the player's choice
	while (std::getline(file, line)) {
		playerScore += resultLetterValue[line.back() - 'X'] +
					   getPlayerLetterValue(playerChoiceMapping.at(line));
	}
	file.close();

	return playerScore;
}

int main()
{
	std::cout << dayMessage << std::endl;
	std::cout << "Part One: " << partOne() << std::endl;
	std::cout << "Part Two: " << partTwo() << std::endl;
}