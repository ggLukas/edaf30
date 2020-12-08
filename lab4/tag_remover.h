#ifndef TAG_REMOVER_H
#define TAG_REMOVER_H

#include <iostream>
#include <sstream>

class TagRemover{
public:
    TagRemover()=delete;
    TagRemover(std::istream &in);
    void print(std::ostream &out);
private:
    std::stringstream stream;
};

std::string findReplacement(std::string &code);

#endif