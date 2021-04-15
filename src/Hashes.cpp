//
//  Hashes.cpp
//  test
//
//  Created by RAIDEMOT on 15.04.2021.
//

#include "Hashes.hpp"

Hashes::Hashes(){}

unsigned long long Hashes::asciiHash(std::string path) {
    
    std::ifstream file(path);
    std::set<unsigned long long> keysSet;
    std::string key;
    
    unsigned int collisions = 0;
    
    while (file >> key)
    {
        unsigned long long sum = 0;
        for (auto ch : key) sum += ch;
        collisions += !keysSet.emplace(sum % (1 << size)).second;
        
    }
    
    return collisions;
    
}

unsigned long long Hashes::polyHash(std::string path) {
    
    std::ifstream file(path);
    std::set<unsigned long long> keysSet;
    std::string key;
    
    unsigned int collisions = 0;
    
    while (file >> key)
    {
        unsigned long long sum = 0;
        for (unsigned int i = 0; i < key.size();)
        {
            sum += this->quickPow(key[i], ++i);
        }
        
        collisions += !keysSet.emplace(sum % (1 << size)).second;
    }
    
    return collisions;
    
}


unsigned long long Hashes::quickPow(int number, unsigned int power) {
    unsigned long long res = 1;
    while (power) {
        if (power & 1)
            res *= number;
        number *= number;
        power >>= 1;
    }
    return res;
}

bool Hashes::setSizeHash(unsigned int size) {
    this->size = size;
    
    return true;
}


