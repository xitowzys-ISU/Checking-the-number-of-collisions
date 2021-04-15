//
//  Files.cpp
//  test
//
//  Created by RAIDEMOT on 15.04.2021.
//

#include "Files.hpp"


Files::Files(){}

// Вывести список инициализированных файлов
void Files::printInitFile()
{
    for(int i = 0; i < pathFiles.size(); i++)
    {
        std::cout << i << ") "<< pathFiles[i].first << " → \"" << pathFiles[i].second << "\"\n";
    }
}

// Список файлов для дальнейших манипуляций
void Files::setPathFile(std::string nameFile, std::string path)
{
    pathFiles.push_back(make_pair(nameFile, path));
}

// Получить количество инициализированных файлов
int Files::getNumberFiles()
{
    return pathFiles.size();
}

std::string Files::getPath(unsigned int index) {
    return pathFiles[index].second;
}
