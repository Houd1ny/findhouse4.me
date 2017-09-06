#include "SearchPageController.h"

#include <string>

Business::SearchPageController::SearchPageController(Poco::SharedPtr<Data::AbstractFileSystem> fileSystem)
    :_abstractFileSystem(fileSystem)
{
    
}

std::string  Business::SearchPageController::generatePage()
{
    return _abstractFileSystem->requestFrontendFile("map.html");
}