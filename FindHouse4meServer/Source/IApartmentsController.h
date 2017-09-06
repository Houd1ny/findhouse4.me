#ifndef ABSTRACTAPARTMENTSCONTROLER_H
#define ABSTRACTAPARTMENTSCONTROLER_H

#include <vector>
#include "Appartment.h"

namespace Business 
{
    
class IApartmentsController 
{
public:
    virtual std::vector<Data::Appartment> getAppartments() = 0;
    virtual ~IApartmentsController(){};
};

};

#endif /* ABSTRACTAPARTMENTSCONTROLER_H */

