#ifndef ABSTRACTREPORTHANDLER_H
#define ABSTRACTREPORTHANDLER_H

#include "Poco/Net/HTTPRequestHandler.h"

namespace Services
{
    
class AbstractReportHandler : public Poco::Net::HTTPRequestHandler{
public:
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, 
                               Poco::Net::HTTPServerResponse& response) = 0;
    virtual ~AbstractReportHandler(){}
};

}

#endif /* ABSTRACTREPORTHANDLER_H */

