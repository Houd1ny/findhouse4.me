#ifndef FILEREQUESTHANDLER_H
#define FILEREQUESTHANDLER_H

#include "AbstractRequestHandler.h"

namespace Services
{
    
class FileRequestHandler : public Services::AbstractRequestHandler {
public:
    virtual void handleRequest(Poco::Net::HTTPServerRequest& request, 
                               Poco::Net::HTTPServerResponse& response);
    virtual ~FileRequestHandler();
};

}
#endif /* FILEREQUESTHANDLER_H */

