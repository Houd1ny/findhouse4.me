#ifndef ABSTRACTREPORTHANDLER_H
#define ABSTRACTREPORTHANDLER_H

#include "Poco/Net/HTTPRequestHandler.h"

namespace Services
{
    
class AbstractRequestHandler : public Poco::Net::HTTPRequestHandler{
public:
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, 
                               Poco::Net::HTTPServerResponse& response) = 0;
    virtual ~AbstractRequestHandler(){}
};

}

#endif /* ABSTRACTREPORTHANDLER_H */

