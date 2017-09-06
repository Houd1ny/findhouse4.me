#ifndef ABSTRACTFILESYSTEM_H
#define ABSTRACTFILESYSTEM_H

#include <string>

namespace Data
{
    
class AbstractFileSystem {
public:
    virtual std::string requestFrontendFile(std::string path) = 0;
    virtual ~AbstractFileSystem(){};
};
    
}
#endif /* ABSTRACTFILESYSTEM_H */

