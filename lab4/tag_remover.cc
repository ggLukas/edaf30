#include "tag_remover.h"
#include <fstream>
#include <iterator>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using std::begin;
using std::end;
using std::find;
using std::ifstream;
using std::ofstream;

int main()
{
    ifstream in("testA1.html");
    ofstream out{"testA1result.html"};
    TagRemover tr{in};
    tr.print(out);
    // std::cout << std::endl;
}

std::string findReplacement(std::string &code)
{
    if (code.compare("&amp;")==0)
        return "&";
    if (code.compare("&nbsp;")==0)
        return " ";
    if (code.compare("&lt;")==0)
        return "<";
    if (code.compare("&gt;")==0)
        return ">";
    return code;
}

TagRemover::TagRemover(std::istream &in)
{
    std::string all;
    std::getline(in, all, {});

    // remove all tags
    auto start = find(all.begin(), all.end(), '<');
    while (start != all.end())
    {
        auto end = find(start, all.end(), '>');
        all.replace(start, end+1, "");
        start = find(all.begin(), all.end(), '<');
    }

    // replace all special character codes
    auto startPos = all.find('&');
    while (startPos != std::string::npos)
    {
        auto endPos = all.find(';', startPos);
        auto toReplace = all.substr(startPos, endPos - startPos + 1);
        all.replace(startPos, toReplace.length(), findReplacement(toReplace));
        startPos = all.find('&', startPos + 1);
    }

    // remove duplicate spaces
    auto duplicateSpace = all.find("  ");
    while(duplicateSpace != std::string::npos){
        all.replace(duplicateSpace, 2, " ");
        duplicateSpace = all.find("  ");
    }

    stream << all;
}

void TagRemover::print(std::ostream &out)
{
    out << stream.rdbuf();
}
