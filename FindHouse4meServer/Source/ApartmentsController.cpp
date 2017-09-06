#include "ApartmentsController.h"

Business::ApartmentsController::ApartmentsController(Poco::SharedPtr<Data::AbstractDB>abstractDB)
    :_abstractDB(abstractDB)
{
}

std::vector<Data::Appartment> Business::ApartmentsController::getAppartments()
{
    return _abstractDB->requestAppartments();
}

Business::ApartmentsController::~ApartmentsController()
{
    
}