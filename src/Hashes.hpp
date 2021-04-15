//
//  Hashes.hpp
//  test
//
//  Created by RAIDEMOT on 15.04.2021.
//

#ifndef Hashes_hpp
#define Hashes_hpp

#include <cmath>
#include <iostream>
#include <fstream>
#include <set>

class Hashes
{
private:
    unsigned int size;
    int getCollisionAmount();
    
    unsigned long long quickPow(int number, unsigned int power);
    
public:
    Hashes();
    bool setSizeHash(unsigned int size);
    
    
    unsigned long long asciiHash(std::string path);
    
    unsigned long long polyHash(std::string path);
    
//    unsigned long long midSquareHash(std::string path);
//
//    unsigned long long ShiftHash(std::string path);

};

#endif /* Hashes_hpp */
