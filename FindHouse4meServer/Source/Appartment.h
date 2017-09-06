#ifndef APPARTMENT_H
#define APPARTMENT_H

#include <string>

namespace Data 
{
    
struct Appartment {
    std::string link;
    std::string coordinates;
    std::string lastUpdated;
    int price;
    int daysOnSite;
};

};



#endif /* APPARTMENT_H */

