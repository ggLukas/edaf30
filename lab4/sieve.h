#ifndef SIEVE_H
#define SIEVE_H

#include <vector>
#include <string>
#include <iostream>
#include <assert.h>


class Sieve {
    public:
        Sieve()=delete;
        Sieve(size_t nbrs);
        std::vector<int> get_primes();
        int get_highest_prime();
        void test();
    private:
        std::string primes;
        std::string correct = "CCPPCPCPCCCPCPCCCPCPCCCPCCCCCPCPCCCC";
};


#endif