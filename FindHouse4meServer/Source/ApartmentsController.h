
/* 
 * File:   ApartmentsController.h
 * Author: yuriy
 *
 * Created on September 6, 2017, 2:16 PM
 */

#ifndef APARTMENTSCONTROLLER_H
#define APARTMENTSCONTROLLER_H

#include "Poco/SharedPtr.h"
#include "AbstractApartmentsController.h"
#include "AbstractDB.h"

namespace Business 
{
    
class ApartmentsController : public AbstractApartmentsController
{
public:
    ApartmentsController(Poco::SharedPtr<Data::AbstractDB> abstractDB);
    virtual std::vector<Data::Appartment> getAppartments() override;
    virtual ~ApartmentsController();
private:
    Poco::SharedPtr<Data::AbstractDB> _abstractDB;
};

};

#endif /* APARTMENTSCONTROLLER_H */

