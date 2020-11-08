#ifndef __CODING_H
#define __CODING_H
#include <iostream>

unsigned char encode(unsigned char c);
unsigned char decode(unsigned char c);
void code_file(std::string infile, std::string outfile, bool encoded);

#endif
