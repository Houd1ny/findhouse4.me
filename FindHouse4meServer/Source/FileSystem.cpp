#include "FileSystem.h"
#include "Poco/FileStream.h"
#include "Poco/Path.h"
#include <iostream>

Data::FileSystem::FileSystem(std::string frontendFolderPath)
    :_frontendFolderPath(frontendFolderPath)
{
}

std::string Data::FileSystem::requestFrontendFile(std::string path)
{
    Poco::Path rootPath(_frontendFolderPath);
    Poco::Path relative(path);
    rootPath.append(path);
    Poco::FileInputStream requestedFileStream(rootPath.toString());
    std::string page(std::istreambuf_iterator<char>(requestedFileStream), {});
    return page;
}


Data::FileSystem::~FileSystem()
{
    
}