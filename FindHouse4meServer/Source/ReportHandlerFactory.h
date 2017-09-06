#ifndef REPORTHANDLERFACTORY_H
#define REPORTHANDLERFACTORY_H

#include "AbstractRequestHandlerFactory.h"
#include "IApartmentsController.h"
#include "Poco/SharedPtr.h"
#include "ISearchPageController.h"

namespace Services{
    
class ReportHandlerFactory : public Services::AbstractRequestHandlerFactory {
public:
    ReportHandlerFactory(Poco::SharedPtr<Business::IApartmentsController> controller,
            Poco::SharedPtr<Business::ISearchPageController>  searchPageController);
    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request) override;
    virtual ~ReportHandlerFactory();
private:
    Poco::SharedPtr<Business::IApartmentsController> _abstractApartmentsController;
    Poco::SharedPtr<Business::ISearchPageController> _searchPageController;
};

};
#endif /* REPORTHANDLERFACTORY_H */

