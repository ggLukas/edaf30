#include "tag_remover.h"
#include <fstream>
#include <fstream>
#include <iterator>
#include <algorithm>

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
}

TagRemover::TagRemover(std::istream &in)
{

    // std::string line;

    // while (std::getline(in, line))
    // {
    //     auto tagStart = find(begin(line), end(line), '<');
    //     while (tagStart != end(line))
    //     {
    //         auto tagEnd = find(tagStart, end(line), '>');
    //         line.replace(tagStart, ++tagEnd, "");
    //         tagStart = find(tagStart, end(line), '<');
    //     }

    //     stream << line << std::endl;
    // }

    std::string all;
    std::string s;
    while (std::getline(in, s))
    {
        all.append(s);
        all.append("\n");
    }

    auto start = find(all.begin(), all.end(), '<');
    while (start != all.end())
    {
        auto end = find(start, all.end(), '>');
        all.replace(start, ++end, "");
        start = find(all.begin(), all.end(), '<');
    }

    size_t startPos = all.find('&');
    auto endPos = all.find(';');
    std::cout << all.length() << std::endl;
    while (startPos != std::string::npos && endPos != std::string::npos)
    {
        auto toReplace = all.substr(startPos, endPos-startPos+1);
        std::cout << toReplace << std::endl;
        if (toReplace.compare("&lt;") == 0)
        {
            all.replace(startPos, 1+endPos - startPos, "<");
        }
        else if (toReplace.compare("&gt;") == 0)
        {
            all.replace(startPos, 1 + endPos - startPos, ">");
        }
        else if (toReplace.compare("&nbsp;") == 0)
        {
            all.replace(startPos, 1+endPos - startPos, " ");
        }
        else if (toReplace.compare("&amp;") == 0)
        {
            all.replace(startPos, 1+endPos - startPos, "&");
        }
        startPos = all.find('&');
        endPos = all.find(';');
    }
    
    stream << all;
}

void TagRemover::print(std::ostream &out)
{
    std::string line;
    while (std::getline(stream, line))
    {
        out << line << std::endl;
    }
}
