#include "ReportHandlerFactory.h"

#include "Poco/Net/HTTPRequestHandler.h"
#include "Poco/Net/HTTPRequestHandlerFactory.h"
#include "Poco/Net/HTTPServerParams.h"
#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Net/HTTPServerParams.h"

#include "ApartmentsListRequestHandler.h"

using namespace Poco;
using namespace Poco::Net;

Services::ReportHandlerFactory::ReportHandlerFactory(Poco::SharedPtr<Business::AbstractApartmentsController> controller)
    :_abstractApartmentsController(controller)
{
}

HTTPRequestHandler* Services::ReportHandlerFactory::createRequestHandler(const HTTPServerRequest& request)
{
    if (request.getURI() == "/get_apartments")
        return new ApartmentsListRequestHandler(_abstractApartmentsController);
    else
        return 0;
}

Services::ReportHandlerFactory::~ReportHandlerFactory()
{
}
