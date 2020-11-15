#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "helpers.h"

using std::string;
using std::vector;




int main()
{
    std::ifstream dict_words{"dict-words.txt"};
    std::ofstream processed_words{"words.txt"};

    string word{};
    while (std::getline(dict_words, word))
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        processWord(processed_words, word);
    }

    return 0;
}
