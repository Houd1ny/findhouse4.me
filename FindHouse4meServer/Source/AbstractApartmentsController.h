#ifndef ABSTRACTAPARTMENTSCONTROLER_H
#define ABSTRACTAPARTMENTSCONTROLER_H

#include <vector>
#include "Appartment.h"

namespace Business 
{
    
class AbstractApartmentsController 
{
public:
    virtual std::vector<Data::Appartment> getAppartments() = 0;
    virtual ~AbstractApartmentsController(){};
};

};

#endif /* ABSTRACTAPARTMENTSCONTROLER_H */

