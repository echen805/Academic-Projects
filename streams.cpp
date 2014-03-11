#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

int get_words_in_line(string line) {
	// To get the number of words, we are going to turn the
	// string into an istreamstring, then pull in one word at a time

	istringstream current_line_as_stream(line);
	int num_words_in_line = 0;

	while (current_line_as_stream.good()) {
		string current_word;
		current_line_as_stream >> current_word;
		num_words_in_line++;
	}

	return num_words_in_line;
}

void main() {
	// Get the filename to open
	cout << "Hello, please input a file name: ";
	string filename;
	getline(cin, filename);

	// Open the file for reading
	ifstream input_file;
	input_file.open(filename);

	// Check if the file was opened correctly
	if (!input_file.good()) {
		cout << "Failed to open the file. Exiting." << endl;
		return;
	}

	// Store each line of the file into a vector
	vector<string> lines;
	string current_line;

	while (input_file.good()) {
		getline(input_file, current_line);
		lines.push_back(current_line);
		cout << current_line << endl;
	}

	// Close the file stream
	input_file.close();

	// Calculate the number of characters, words and lines in the file
	int num_characters = 0;
	int num_words = 0;
	int num_lines = lines.size();

	for (int i = 0; i < lines.size(); i++) {
		string current_line = lines[i];
		num_words += get_words_in_line(current_line);
		num_characters += current_line.size();
	}

	// Print out the values we've calculated
	cout << "The number of lines is " << num_lines << endl;
	cout << "The number of words is " << num_words << endl;
	cout << "The number of chars is " << num_characters << endl;
}