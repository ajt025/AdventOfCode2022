#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

const std::string dayMessage = "Day 1";
const std::string inputFilename = "input.txt";

int partOne() {
	// Create a text string, which is used to output the text file
	std::string line;
	// Create file stream instance to read file
	std::ifstream file(inputFilename);

	int max = INT_MIN;
	int curr = 0;
	// iterate each line, checking max and resetting the summation on every blank line
	while (std::getline(file, line)) {
		// max check
		if (line.length() == 0) {
			max = std::max(max, curr);
			curr = 0;
		} else {
			// add the current number to the running total
			curr += std::stoi(line);
		}
	}
	file.close();

	return max;
}

int partTwo(int topK) {
	// Create a text string, which is used to output the text file
	std::string line;
	// Create file stream instance to read file
	std::ifstream file(inputFilename);

	std::vector<int> totals;
	int curr = 0;
	// iterate each line, reset running total on every blank line
	while (std::getline(file, line)) {
		// max check
		if (line.length() == 0) {
			totals.push_back(curr);
			curr = 0;
		} else {
			// add the current number to the running total
			curr += std::stoi(line);
		}
	}
	file.close();

	// sort the totals and pull specified elements
	std::sort(totals.begin(), totals.end(), std::greater<int>());
	return std::accumulate(totals.begin(), totals.begin() + topK, 0);
}

int main()
{
	std::cout << dayMessage << std::endl;
	std::cout << "Part One: " << partOne() << std::endl;
	std::cout << "Part Two: " << partTwo(3) << std::endl;
}