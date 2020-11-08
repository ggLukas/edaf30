
#include "editor.h"
#include <string>

using std::string;

using size_type = Editor::size_type;

size_type Editor::get_size() const
{
    return text.size();
}

size_type Editor::find_left_par(size_type pos) const
{   
    char current = text[pos];
    char target;
    int counter = 1;
    if (current == ')')
        target = '(';
    else if (current == '}')
        target = '{';
    else if (current == ']')
        target = '[';

    for (int i = pos - 1; i >= 0; i--)
    {
        if (text[i] == current) counter++;
        else if (text[i] == target) counter--;
        if (counter == 0) 
            return i;
    }
    return string::npos;
}