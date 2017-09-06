#ifndef ABSTRACTDB_H
#define ABSTRACTDB_H

#include <vector>

#include "Appartment.h"

namespace Data {
    
class AbstractDB {
public:
    virtual std::vector<Data::Appartment> requestAppartments() = 0;
    virtual ~AbstractDB(){};
private:

};

};

#endif /* ABSTRACTDB_H */

