#include "SearchPageRequestHandler.h"

#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Util/Application.h"
#include "Poco/Logger.h"

using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;

Services::SearchPageRequestHandler::SearchPageRequestHandler(Poco::SharedPtr<Business::ISearchPageController> searchControler)
    :_searchControler(searchControler)
{
    
}

#include <iostream>

void Services::SearchPageRequestHandler::handleRequest(Poco::Net::HTTPServerRequest& request, 
                               Poco::Net::HTTPServerResponse& response)
{
    std::string mainPage = _searchControler->generatePage();
    response.setChunkedTransferEncoding(true);
    response.setContentType("text/html");
    response.add("Access-Control-Allow-Origin", "null");
    std::ostream& ostr = response.send();
    ostr << mainPage;
}

Services::SearchPageRequestHandler::~SearchPageRequestHandler()
{
}