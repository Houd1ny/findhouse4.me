#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include "AbstractFileSystem.h"

namespace Data
{
    
class FileSystem : public Data::AbstractFileSystem {
public:
    FileSystem(std::string frontendFolderPath);
    virtual std::string requestFrontendFile(std::string path) override;
    ~FileSystem();
private:
    std::string _frontendFolderPath;
};

}
#endif /* FILESYSTEM_H */

