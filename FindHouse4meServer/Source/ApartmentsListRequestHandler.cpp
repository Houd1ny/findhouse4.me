#include "ApartmentsListRequestHandler.h"

#include "Poco/Net/HTTPServerRequest.h"
#include "Poco/Net/HTTPServerResponse.h"
#include "Poco/Util/Application.h"
#include "Poco/Logger.h"
#include "Poco/JSON/Array.h"
#include "Poco/JSON/Object.h"

using Poco::Net::HTTPServerRequest;
using Poco::Net::HTTPServerResponse;
using Poco::JSON::Array;
using Poco::JSON::Object;

Services::ApartmentsListRequestHandler::ApartmentsListRequestHandler(Poco::SharedPtr<Business::AbstractApartmentsController> controller)
    :_abstractApartmentsController(controller)
{
}

void Services::ApartmentsListRequestHandler::handleRequest(HTTPServerRequest& request, 
                                                           HTTPServerResponse& response)
{
    Poco::Util::Application& app = Poco::Util::Application::instance();
    app.logger().information("ApartmentsListRequestHandler:Request from " + request.clientAddress().toString());
    std::vector<Data::Appartment> appartments = _abstractApartmentsController->getAppartments();
        
    Array appartmentsJson;
    for (int i = 0; i < appartments.size(); ++i)
    {
        Object appartment;
        appartment.set("link", appartments[i].link);
        appartment.set("coordinate", appartments[i].coordinates);
        appartment.set("lastUpdated", appartments[i].lastUpdated);
        appartment.set("price", appartments[i].price);
        appartment.set("daysOnSite", appartments[i].daysOnSite);
        appartmentsJson.add(appartment);
     }
    
    response.setChunkedTransferEncoding(true);
    response.setContentType("application/json");
    response.add("Access-Control-Allow-Origin", "null");
    std::ostream& ostr = response.send();
    appartmentsJson.stringify(ostr);
}