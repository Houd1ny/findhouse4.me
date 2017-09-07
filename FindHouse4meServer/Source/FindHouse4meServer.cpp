#include "FindHouse4meServer.h"

#include "Poco/Net/HTTPServer.h"
#include "ReportHandlerFactory.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Net/HTTPServerParams.h"
#include "ApartmentsController.h"
#include "ReportHandlerFactory.h"
#include "SqlLiteDb.h"
#include "FileSystem.h"
#include "SearchPageController.h"

using namespace std;

void FindHouse4meServer::initialize(Application& self)
{
    loadConfiguration();
    initData();
    initBusiness();
    initServices();
    ServerApplication::initialize(self);
}

void FindHouse4meServer::uninitialize()
{
    ServerApplication::uninitialize();
}

void FindHouse4meServer::initData() 
{
    Poco::Data::SQLite::Connector::registerConnector();
    std::string coonectionString = config().getString("Server.connectionString", 
            "/home/yuriy/test/real_estate_parser/appartments1.db");
    
    _abstractDB = new Data::SqlLiteDb(coonectionString);
    
    std::string frontendFolder = config().getString("Server.frontedFolder", 
            "/home/yuriy/test/findhouse4.me/FindHouse4meServer/Frontend");
        
    _abstractFileSystem = new Data::FileSystem(frontendFolder);
}

void FindHouse4meServer::initBusiness() 
{
    _searchPageController = new Business::SearchPageController(_abstractFileSystem);
    _abstractApartmentsController = new Business::ApartmentsController(_abstractDB);
}

void FindHouse4meServer::initServices() 
{
    _abstractReportHandlerFactory = 
            new Services::ReportHandlerFactory(_abstractApartmentsController, _searchPageController);
}


void FindHouse4meServer::defineOptions(Poco::Util::OptionSet& options)
{
}

void FindHouse4meServer::handleOption(const string& name, const string& value)
{
    ServerApplication::handleOption(name, value);

}

int FindHouse4meServer::main(const std::vector<string>& args)
{
    unsigned short port = (unsigned short) config().getInt("Server.port", 9980);
    int maxQueued  = config().getInt("Server.maxQueued", 100);
    int maxThreads = config().getInt("Server.maxThreads", 8);
    Poco::ThreadPool::defaultPool().addCapacity(maxThreads);

    Poco::Net::HTTPServerParams* pParams = new Poco::Net::HTTPServerParams;
    pParams->setMaxQueued(maxQueued);
    pParams->setMaxThreads(maxThreads);

    Poco::Net::ServerSocket svs(port);
    Poco::Net::HTTPServer srv(_abstractReportHandlerFactory, svs, pParams);
    srv.start();
    waitForTerminationRequest();
    srv.stop();

    return Application::EXIT_OK;
}
