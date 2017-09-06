#ifndef APARTMENTSLISTREQUESTHANDLER_H
#define APARTMENTSLISTREQUESTHANDLER_H

#include "AbstractReportHandler.h"
#include "AbstractApartmentsController.h"
#include "Poco/SharedPtr.h"

namespace Services {
    
class ApartmentsListRequestHandler : public Services::AbstractReportHandler {
public:
    ApartmentsListRequestHandler(Poco::SharedPtr<Business::AbstractApartmentsController> controller);
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, 
                               Poco::Net::HTTPServerResponse& response);
private:
    Poco::SharedPtr<Business::AbstractApartmentsController> _abstractApartmentsController;
};

};
#endif /* APARTMENTSLISTREQUESTHANDLER_H */

