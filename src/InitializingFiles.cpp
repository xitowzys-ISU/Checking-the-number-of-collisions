//
//  InitializingFiles.cpp
//  test
//
//  Created by RAIDEMOT on 15.04.2021.
//

#include "InitializingFiles.hpp"


InitializingFiles::InitializingFiles(){}

InitializingFiles::InitializingFiles(Files* files, std::string filePath)
{
    openFile(files, filePath);
}

bool InitializingFiles::openFile(Files* files, std::string filePath)
{
    using namespace std;
    
    ifstream in;
    
    in.open(filePath, ios::binary);
    
    
    if(in.is_open())
    {
        regex regular("[a-zA-Z]\\w+[\.][a-zA-Z]\\w+");

        cmatch what;

        if (regex_search(filePath.c_str(), what, regular))
        {
            files->setPathFile(what[0].first, filePath);
        }
        else
        {
            files->setPathFile("error", filePath);
        }
        
        return true;
    }
    else
    {
        return false;
    };
}
