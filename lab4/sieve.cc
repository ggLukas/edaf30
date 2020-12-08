#include <string>
#include <iostream>
#include <istream>
#include <ostream>
#include <algorithm>
#include "sieve.h"

#define UPPER_BOUND 100000

int main()
{

    Sieve s{35};
    s.test();
    std::cout << "Primes up to 35 =======> ";
    for (auto p : s.get_primes())
    {
        std::cout << p << " ";
    }
    std::cout << std::endl;

    Sieve s2{UPPER_BOUND};
    std::cout << "Highest prime less than " << UPPER_BOUND << " =======> " << s2.get_highest_prime() << std::endl;
}

Sieve::Sieve(size_t nbrs)
{
    primes.assign(nbrs + 1, 'P');
    primes[0] = 'C';
    primes[1] = 'C';
    for (size_t i = 2; i < primes.length(); i++)
    {
        if (primes[i] == 'P')
        {
            size_t counter = i * 2;
            while (counter <= nbrs)
            {
                primes[counter] = 'C';
                counter += i;
            }
        }
    }
}

std::vector<int> Sieve::get_primes()
{
    std::vector<int> v{};
    for (size_t i = 0; i < primes.length(); i++)
    {
        if (primes.at(i) == 'P')
            v.push_back(i);
    }

    return v;
}

int Sieve::get_highest_prime()
{
    return primes.rfind('P');
}

void Sieve::test()
{
    assert(primes.compare(correct) == 0);
}