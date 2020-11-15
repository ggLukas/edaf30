#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include "word.h"
#include "dictionary.h"
#include "helpers.h"

using std::string;
using std::vector;

Dictionary::Dictionary()
{
	std::ifstream in{"words.txt"};
	string line;
	while (std::getline(in, line))
	{
		word_set.insert(line.substr(0, line.find(' ')));
	}

	in.clear();
	in.seekg(0);

	while (std::getline(in, line))
	{
		transform(line.begin(), line.end(), line.begin(), ::tolower);
		string delimiter = " ";

		size_t pos = 0;

		// Find word
		pos = line.find(delimiter);
		string word = line.substr(0, pos);
		line.erase(0, pos + delimiter.length());

		// Get amount of trigrams
		pos = line.find(delimiter);
		int nbr_of_trigrams = std::stoi(line.substr(0, pos));
		line.erase(0, pos + delimiter.length());

		vector<string> trigrams;
		// Add all trigrams
		for (size_t i = 0; i < nbr_of_trigrams; i++)
		{
			pos = line.find(delimiter);
			string trigram = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			trigrams.push_back(trigram);
		}

		words[word.length()].push_back(Word{word, trigrams});
	}
}

bool Dictionary::contains(const string &word) const
{
	return word_set.find(word) != word_set.end();
}

void Dictionary::add_trigram_suggestions(vector<string> &suggestions, const string &word) const
{
	int nbr_of_trigrams = word.length() - 2;
	if (nbr_of_trigrams < 0)
		nbr_of_trigrams = 0;

	vector<string> trigrams = processTrigrams(word, nbr_of_trigrams);

	for (size_t i = word.length() - 1; i <= word.length() + 1; i++)
	{
		if (i > 24)
			continue;
		vector<Word> potential_word_suggestions = words[i];
		for (Word w : potential_word_suggestions)
		{
			int matches = w.get_matches(trigrams);
			if (matches >= nbr_of_trigrams / 2)
				suggestions.push_back(w.get_word());
		}
	}
}

void Dictionary::rank_suggestions(vector<string> &suggestions, const string &word) const
{
	std::map<string, int> map;

	for (string s : suggestions)
	{
		int d[MAX_LENGTH][MAX_LENGTH];

		for (size_t i = 0; i < MAX_LENGTH; i++)
			d[i][0] = i;
		for (size_t j = 0; j < MAX_LENGTH; j++)
			d[0][j] = j;

		for (size_t j = 1; j < MAX_LENGTH; j++)
		{
			for (size_t i = 1; i < MAX_LENGTH; i++)
			{
				int cost_one = s[i] == word[j] ? d[i - 1][j - 1] : d[i - 1][j - 1] + 1;
				int cost_two = d[i - 1][j] + 1;
				int cost_three = d[i][j - 1] + 1;
				d[i][j] = std::min(std::min(cost_one, cost_two), cost_three);
			}
		}

		map.insert({s, d[word.length()][s.length()]});
	}

	struct CostComparator
	{
		CostComparator(std::map<string, int> map) { this->map = map; }
		bool operator()(const string &word, const string &other)
		{
			return map.at(word) < map.at(other);
		}

		std::map<string, int> map;
	};

	std::sort(suggestions.begin(), suggestions.end(), CostComparator{map});
}

void Dictionary::trim_suggestions(vector<string> &suggestions) const
{
	if(suggestions.size() > 5)
		suggestions.erase(suggestions.begin() + 5, suggestions.end());
}

vector<string> Dictionary::get_suggestions(const string &word) const
{
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}
