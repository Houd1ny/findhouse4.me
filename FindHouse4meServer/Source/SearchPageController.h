#ifndef SEARCHPAGECONTROLLER_H
#define SEARCHPAGECONTROLLER_H

#include "Poco/SharedPtr.h"
#include "ISearchPageController.h"
#include "AbstractFileSystem.h"

namespace Business 
{
    
class SearchPageController : public Business::ISearchPageController {
public:
    SearchPageController(Poco::SharedPtr<Data::AbstractFileSystem> fileSystem);
    virtual std::string generatePage() override;
private:
    Poco::SharedPtr<Data::AbstractFileSystem> _abstractFileSystem;
};

}
#endif /* SEARCHPAGECONTROLLER_H */
