#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <vector>

using std::string;
using std::vector;

string lowercase(const string &word)
{
    string lowerword;
    for (auto c : word)
    {
        lowerword.push_back(tolower(c));
    }
    return lowerword;
}

void processWord(std::ofstream &out, const string &word)
{
    // add the word
    out << lowercase(word) << ' ';

    // add trigram count
    signed long nbrOfTrigrams = word.length() - 2;
    if(nbrOfTrigrams < 0) nbrOfTrigrams = 0;
    out << nbrOfTrigrams << ' ';

    // trigrams
    vector<string> trigrams{};
    for (size_t i = 0; i < nbrOfTrigrams; i++)
    {
        trigrams.push_back(lowercase(word.substr(i, 3)));
    }
    std::sort(trigrams.begin(), trigrams.end());
    for (vector<string>::iterator it = trigrams.begin(); it != trigrams.end(); it++)
    {
        out << *it << ' ';
    }
    out << std::endl;
}

int main()
{
    std::ifstream dict_words{"dict-words.txt"};
    std::ofstream processed_words{"words.txt"};

    string word{};
    while (std::getline(dict_words, word))
    {
        processWord(processed_words, word);
    }

    return 0;
}
