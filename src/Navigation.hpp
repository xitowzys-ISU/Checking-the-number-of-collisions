//
//  Navigation.hpp
//  test
//
//  Created by RAIDEMOT on 15.04.2021.
//

#ifndef Navigation_hpp
#define Navigation_hpp

#include <string>
#include <iostream>
#include <set>

#include "Files.hpp"
#include "Hashes.hpp"
#include "InitializingFiles.hpp"

class Navigation
{
private:
    unsigned short choice;
    Files *ptrFiles;
    Hashes *ptrHashes;
    
    // Модули //
    void setSizeHash();
    void askiiHash();
    void polyHash();
    void midSquareHash();
    void hashShift();
    
    void inputError();
    
    unsigned int selectOneFile(std::string title);
    
public:
    Navigation();
    
    // Интерфейс инициализация файлов
    void openingFiles();
    
    // Интерфейс главного меню
    void mainMenu();
    
    
};


#endif /* Navigation_hpp */
