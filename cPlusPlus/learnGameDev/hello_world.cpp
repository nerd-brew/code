// A program that reads data from a text file, and outputs the words and line count to a text file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    cout << "~~ Word and Line Counter ~~" << endl;
    cout << "Enter the name of the file you want to read from: ";
    string input_file;
    cin >> input_file;
    
    cout << "Enter the name of the file you want to write to: ";
    string output_file;
    cin >> output_file;

    ifstream in_file {input_file};
    ofstream out_file {output_file};

// Checking input and output files
    if (!in_file) {
        cerr << "Error opening input file" << endl;
        return 1;
    }

    if (!out_file) {
        cerr << "Error opening output file" << endl;
        return 1;
    }

// Performing the word and line count operations
    string line;
    int line_count {0};
    int word_count {0};

    while (getline(in_file, line)) {
        line_count++;
        istringstream iss {line};
        string word;
        while (iss >> word) {
            word_count++;
        }
    }

// Writing the word and line count to the output file
    out_file << "Word count: " << word_count << endl;
    out_file << "Line count: " << line_count << endl;

    cout << "Word count: " << word_count << endl;
    cout << "Line count: " << line_count << endl;

    in_file.close();
    out_file.close();

    return 0;

}