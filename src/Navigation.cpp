//
//  Navigation.cpp
//  test
//
//  Created by RAIDEMOT on 15.04.2021.
//

#include "Navigation.hpp"

using namespace std;

Navigation::Navigation(){}

void Navigation::openingFiles() {
    
    string path;
    ptrFiles = new Files();
    ptrHashes = new Hashes();
    InitializingFiles iF;
    
    int i = 0;
    
    do
    {
        cout.flush();
        
        cout << "Введите путь к файлу. Ввведите \"0\", чтобы перейти к манипулятору" << endl;
         
        string path = "";
        
        // [ТЕСТИРОВАНИЕ]
        path = "../../../data/endict";
        path += ".txt";
        i++;
        // [ТЕСТИРОВАНИЕ]
        
//        getline(cin, path);

        if(path == "0")
            break;

        if(iF.openFile(ptrFiles, path)) {
            cout << "-----------------------------------------------------------------\n";
            cout << "Файл был успешно добавлен" << endl;
            cout << "-----------------------------------------------------------------\n";
        }
        else {
            cout << "-----------------------------------------------------------------\n";
            cout << "Файл не удалось открыть, введите правильный путь к файлу" << endl;
            cout << "-----------------------------------------------------------------\n";
        }
        
    }
    while (i > 1);
}

void Navigation::mainMenu() {
    
    do
    {
        if(!(ptrFiles->getNumberFiles() > 0)) {
            cout << "-----------------------------------------------------------------\n";
            cout << "Главное меню не доступно, так как не были добавлены файлы\n";
            cout << "-----------------------------------------------------------------\n";
            break;
        }
        
        cout << "-----------------------------------------------------------------\n";
        cout << "Главное меню\n";
        cout << "1 - Посмотреть список добавленных файлов\n";
        cout << "2 - Задать размер хэша\n";
        cout << "-----------------------------------------------------------------\n";
        cout << "3 - ASCII hash\n";
        cout << "4 - Poly hash\n";
        cout << "5 - Mid square hash\n";
        cout << "6 - Shift hash\n";
        cout << "-----------------------------------------------------------------\n";
        cout << "0 - Выход\n";
        cout << "Выполнить: ";
        
        
        if(!(cin >> choice)) {
            inputError();
            choice = sizeof(choice);
            continue;
         }
        
        cout << "-----------------------------------------------------------------\n";

        switch(choice) {
            case 0:
                cout << "До свидание)\n";
                cout << "-----------------------------------------------------------------\n";
                break;
            case 1:
                ptrFiles->printInitFile();
                break;
            case 2:
                setSizeHash();
                break;
            case 3:
                askiiHash();
                break;
            case 4:
                polyHash();
                break;
            case 5:
                midSquareHash();
                break;
            case 6:
                hashShift();
                break;
            default:
                cout << "Извините, но такой команды нету\n";
         }
    }
    while(choice != 0);
}

void Navigation::setSizeHash() {
    unsigned int size;
    
    do
    {
        cout << "-----------------------------------------------------------------\n";
        cout << "Установить размер хэша\n";
        cout << "Введите размер: ";
        
        if(!(cin >> size)) {
            inputError();
            choice = sizeof(choice);
            continue;
         }
        
        if(ptrHashes->setSizeHash(size)) {
            cout << "-----------------------------------------------------------------\n";
            cout << "Размер установлен!\n";
            cout << "-----------------------------------------------------------------\n";
            break;
        } else {
            cout << "-----------------------------------------------------------------\n";
            cout << "Неизвестная ошибка. Размер не был задан!\n";
            cout << "-----------------------------------------------------------------\n";
            continue;
        }
        
        cout << "-----------------------------------------------------------------\n";
    }
    while(1);

}

void Navigation::askiiHash() {
    
    unsigned int indexFile;
    
    indexFile = this->selectOneFile("askiiHash");
    
    std::cout << ptrHashes->asciiHash(ptrFiles->getPath(indexFile));
    
    mainMenu();
}

void Navigation::polyHash() {
    
    unsigned int indexFile;
    
    indexFile = this->selectOneFile("polyHash");
    
    std::cout << ptrHashes->polyHash(ptrFiles->getPath(indexFile));
    
    mainMenu();
    
}

void Navigation::midSquareHash() {}

void Navigation::hashShift() {}

unsigned int Navigation::selectOneFile(std::string title) {
    unsigned int indexFile;
    
    do
    {
        cout << "-----------------------------------------------------------------\n";
        cout <<  title + "\n";
        ptrFiles->printInitFile();
        cout << "Введите номер файла: ";
        
        if(!(cin >> choice)) {
            inputError();
            choice = sizeof(choice);
            continue;
         }
        
        if (choice > ptrFiles->getNumberFiles())
        {
            cout << "-----------------------------------------------------------------\n";
            cout << "Неверно введен номер, пожалуйста введите заного!\n";
        }
        else
        {
            indexFile = choice;
            cout << "-----------------------------------------------------------------\n";
            cout << "Файл выбран!\n";
            cout << "-----------------------------------------------------------------\n";
            break;
        }
        
        cout << "-----------------------------------------------------------------\n";
    }
    while(1);
    
    return indexFile;
}

void Navigation::inputError() {
    std::cout << "-----------------------------------------------------------------\n";
    std::cout << "Введены символы вместо цифр!\n";
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}
