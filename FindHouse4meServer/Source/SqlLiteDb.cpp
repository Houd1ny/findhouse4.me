#include "SqlLiteDb.h"

#include <vector>
#include <string>
#include "Poco/Data/Session.h"
#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/SessionFactory.h"

using Poco::Data::Session;
using Poco::Data::Statement;
using Poco::Data::SessionFactory;
using namespace Poco::Data::Keywords;

Data::SqlLiteDb::SqlLiteDb(std::string connectionString)
    :_connectionString(connectionString)
{
}

std::vector<Data::Appartment> Data::SqlLiteDb::requestAppartments()
{    
    Session session = SessionFactory::instance().create("sqlite", _connectionString);
    
    std::vector<std::string> links;
    std::vector<std::string> coordinates;
    std::vector<std::string> lastUpdates;
    std::vector<int> prices;
    std::vector<int> daysOnSiteList;
    Statement select(session);
    select << "SELECT *  FROM Appartments",
            into(links), into(coordinates), into(lastUpdates), into(prices), into(daysOnSiteList);
    select.execute();
    std::vector<Data::Appartment> parsedAppartments;
    for (int i = 0; i < links.size(); ++i)
    {
        Data::Appartment appartment;
        appartment.link = links[i];
        appartment.coordinates = coordinates[i];
        appartment.lastUpdated = lastUpdates[i];
        appartment.price = prices[i];
        appartment.daysOnSite = daysOnSiteList[i];
        parsedAppartments.push_back(appartment);
    }
    return parsedAppartments;
}

Data::SqlLiteDb::~SqlLiteDb()
{
    
}