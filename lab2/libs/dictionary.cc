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
	std::ifstream in("words.txt");
	if (!in){
		throw std::runtime_error("could not open file");
	}
	while (in)
	{
		string word;
		in >> word;
		int nbr_of_tris;
		in >> nbr_of_tris;
		vector<std::string> tgs;
		for (int i = 0; i < nbr_of_tris; ++i)
		{
			string tri;
			in >> tri;
			tgs.push_back(tri);
		}
		if (word.size() < MAX_LENGTH){
			word_set.insert(word);
			words[word.size()].push_back(Word(word,tgs));
		}
	}
	in.close();

	
}

bool Dictionary::contains(const string &word) const
{
	return word_set.count(word) >0;
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
