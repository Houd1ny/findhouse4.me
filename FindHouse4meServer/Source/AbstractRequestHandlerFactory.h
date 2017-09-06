#ifndef ABSTRACTREPORTHANDLERFACTORY_H
#define ABSTRACTREPORTHANDLERFACTORY_H

#include "Poco/Net/HTTPRequestHandlerFactory.h"

namespace Services
{
    
class AbstractRequestHandlerFactory : public Poco::Net::HTTPRequestHandlerFactory 
{
public:
    virtual Poco::Net::HTTPRequestHandler* createRequestHandler(const Poco::Net::HTTPServerRequest& request) = 0;
    virtual ~AbstractRequestHandlerFactory(){}
};

}

#endif /* ABSTRACTREPORTHANDLERFACTORY_H */

