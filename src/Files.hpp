//
//  Files.hpp
//  test
//
//  Created by RAIDEMOT on 15.04.2021.
//

#ifndef Files_hpp
#define Files_hpp

#include <vector>
#include <string>
#include <fstream>
#include <iostream>


class Files
{
private:
    // Список путей
    std::vector <std::pair<std::string, std::string>> pathFiles;
    
public:
    Files();

    void printInitFile();
    
    void setPathFile(std::string nameFile, std::string path);
    
    std::string getPath(unsigned int index);
    
    // Получить количество инициализированных файлов
    int getNumberFiles();
    
};


#endif /* Files_hpp */
