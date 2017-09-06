#ifndef FINDHOUSE4MESERVER_H
#define FINDHOUSE4MESERVER_H

#include <string>

#include "Poco/SharedPtr.h"
#include "Poco/Util/ServerApplication.h"
#include "IApartmentsController.h"
#include "AbstractDB.h"
#include "AbstractRequestHandlerFactory.h"
#include "AbstractFileSystem.h"
#include "ISearchPageController.h"

class FindHouse4meServer: public Poco::Util::ServerApplication
{
protected:
    void initialize(Application& self);
    
    void uninitialize();
    
    void initData();
    void initBusiness();
    void initServices();
    
    void defineOptions(Poco::Util::OptionSet& options);
    
    void handleOption(const std::string& name, const std::string& value);
    
    int main(const std::vector<std::string>& args);
private:
    Poco::SharedPtr<Business::IApartmentsController> _abstractApartmentsController;
    Poco::SharedPtr<Business::ISearchPageController> _searchPageController;
    Poco::SharedPtr<Data::AbstractDB> _abstractDB;
    Poco::SharedPtr<Services::AbstractRequestHandlerFactory> _abstractReportHandlerFactory;
    Poco::SharedPtr<Data::AbstractFileSystem> _abstractFileSystem;
};

#endif /* FINDHOUSE4MESERVER_H */

