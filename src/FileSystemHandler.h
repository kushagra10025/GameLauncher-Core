//
// Created by Kushagra on 08-09-2022.
//

#ifndef GAMELAUNCHER_CORE_FILESYSTEMHANDLER_H
#define GAMELAUNCHER_CORE_FILESYSTEMHANDLER_H

#include <filesystem>
#include <vector>

namespace fs = std::filesystem;
namespace GLC {

    class FileSystemHandler {
    public:
        FileSystemHandler();

        bool DoesFileExistInDirectory(fs::path dirToCheck, std::string fileToCheck);
        void GetDirectoryStructure(fs::path dirToCheck, std::vector<fs::path>& pathsInCurrentDirectory);
        void GetEntireDirectoryStructure(fs::path dirToCheck, std::vector<fs::path>& allPathsInCurrentDirectory);
    };

} // GLC

#endif //GAMELAUNCHER_CORE_FILESYSTEMHANDLER_H
