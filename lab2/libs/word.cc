#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "word.h"

using std::string;
using std::vector;

string Word::get_word() const
{
	return word;
}

unsigned int Word::get_matches(const vector<string> &t) const
{
	int matches = 0;
	for (string tri : t)
	{
		for (string other_tri : trigrams)
		{
			int i = tri.compare(other_tri);
			if (i < 0)
				break;
			if (i == 0)
				matches++;
		}
	}

	return matches;
}
