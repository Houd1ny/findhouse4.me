#ifndef FINDHOUSE4MESERVER_H
#define FINDHOUSE4MESERVER_H

#include <string>

#include "Poco/SharedPtr.h"
#include "Poco/Util/ServerApplication.h"
#include "AbstractApartmentsController.h"
#include "AbstractDB.h"
#include "AbstractReportHandlerFactory.h"

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
    Poco::SharedPtr<Business::AbstractApartmentsController> _abstractApartmentsController;
    Poco::SharedPtr<Data::AbstractDB> _abstractDB;
    Poco::SharedPtr<Services::AbstractReportHandlerFactory> _abstractReportHandlerFactory;
};

#endif /* FINDHOUSE4MESERVER_H */

