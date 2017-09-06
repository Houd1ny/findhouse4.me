#ifndef APARTMENTSLISTREQUESTHANDLER_H
#define APARTMENTSLISTREQUESTHANDLER_H

#include "AbstractRequestHandler.h"
#include "IApartmentsController.h"
#include "Poco/SharedPtr.h"

namespace Services {
    
class ApartmentsListRequestHandler : public Services::AbstractRequestHandler {
public:
    ApartmentsListRequestHandler(Poco::SharedPtr<Business::IApartmentsController> controller);
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, 
                               Poco::Net::HTTPServerResponse& response);
private:
    Poco::SharedPtr<Business::IApartmentsController> _abstractApartmentsController;
};

};
#endif /* APARTMENTSLISTREQUESTHANDLER_H */

