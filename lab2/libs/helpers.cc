#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>
#include "helpers.h"

using std::string;
using std::vector;

vector<string> processTrigrams(const string &word, size_t nbr_of_trigrams)
{
    vector<string> trigrams{};
    for (size_t i = 0; i < nbr_of_trigrams; i++)
    {
        trigrams.push_back(word.substr(i, 3));
    }
    std::sort(trigrams.begin(), trigrams.end());

    return trigrams;
}

void processWord(std::ofstream &out, const string &word)
{
    // add the word
    out << word << ' ';

    // add trigram count
    signed long nbr_of_trigrams = word.length() - 2;
    if (nbr_of_trigrams < 0)
        nbr_of_trigrams = 0;
    out << nbr_of_trigrams << ' ';

    // trigrams
    vector<string> trigrams = processTrigrams(word, nbr_of_trigrams);

    for (vector<string>::iterator it = trigrams.begin(); it != trigrams.end(); it++)
    {
        out << *it << ' ';
    }
    out << std::endl;
}