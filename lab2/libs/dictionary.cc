#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;

Dictionary::Dictionary() {
	std::ifstream in{"words.txt"};
	string line;
	while(std::getline(in, line)){
		words.insert(line.substr(0, line.find(' ')));
	}
}

bool Dictionary::contains(const string& word) const {
	return words.find(word) != words.end();
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
