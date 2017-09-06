#ifndef SEARCHPAGEREQUESTHANDLER_H
#define SEARCHPAGEREQUESTHANDLER_H

#include <Poco/SharedPtr.h>

#include "AbstractRequestHandler.h"
#include "ISearchPageController.h"

namespace Services
{

class SearchPageRequestHandler : public Services::AbstractRequestHandler {
public:
    SearchPageRequestHandler(Poco::SharedPtr<Business::ISearchPageController> searchControler);
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, 
                               Poco::Net::HTTPServerResponse& response);
    virtual ~SearchPageRequestHandler();
private:
    Poco::SharedPtr<Business::ISearchPageController> _searchControler;
};


}

#endif /* SEARCHPAGEREQUESTHANDLER_H */

