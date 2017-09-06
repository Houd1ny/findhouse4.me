#ifndef SQLLITEDB_H
#define SQLLITEDB_H

#include "AbstractDB.h"
#include <string>

namespace Data
{

class SqlLiteDb :public Data::AbstractDB{
public:
    SqlLiteDb(std::string connectionString);
    virtual std::vector<Data::Appartment> requestAppartments() override;
    virtual ~SqlLiteDb();
private:
    std::string _connectionString;
};

};
#endif /* SQLLITEDB_H */

