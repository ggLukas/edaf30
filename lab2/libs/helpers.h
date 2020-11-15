#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <vector>

std::string lowercase(const std::string &word);

std::vector<std::string> processTrigrams(const std::string &word, size_t nbr_of_trigrams);

void processWord(std::ofstream &out, const std::string &word);