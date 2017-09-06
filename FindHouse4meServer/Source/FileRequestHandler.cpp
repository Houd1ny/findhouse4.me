#include "FileRequestHandler.h"


#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Util/Application.h"
#include "Poco/Logger.h"

using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;

void Services::FileRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, 
                               Poco::Net::HTTPServerResponse& response)
{
    
}

Services::FileRequestHandler::~FileRequestHandler()
{
}