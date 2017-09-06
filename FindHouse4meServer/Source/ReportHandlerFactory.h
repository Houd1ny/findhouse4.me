#ifndef REPORTHANDLERFACTORY_H
#define REPORTHANDLERFACTORY_H

#include "AbstractReportHandlerFactory.h"
#include "AbstractApartmentsController.h"
#include "Poco/SharedPtr.h"

namespace Services{
    
class ReportHandlerFactory : public Services::AbstractReportHandlerFactory {
public:
    ReportHandlerFactory(Poco::SharedPtr<Business::AbstractApartmentsController>controller);
    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request) override;
    virtual ~ReportHandlerFactory();
private:
    Poco::SharedPtr<Business::AbstractApartmentsController>_abstractApartmentsController;
};

};
#endif /* REPORTHANDLERFACTORY_H */

