#ifndef ISEARCHPAGECONTROLLER_H
#define ISEARCHPAGECONTROLLER_H

#include <string>

namespace Business 
{
    
class ISearchPageController
{
public:
    virtual std::string generatePage() = 0;
};

}

#endif /* ISEARCHPAGECONTROLLER_H */

