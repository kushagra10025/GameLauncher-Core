//
// Created by Kushagra on 08-09-2022.
//

#include "FileSystemHandler.h"

namespace GLC {
    FileSystemHandler::FileSystemHandler() {

    }

    bool FileSystemHandler::DoesFileExistInDirectory(fs::path dirToCheck, std::string fileToCheck) {
        if(fs::exists(dirToCheck) && fs::is_directory(dirToCheck)){
            fs::path fileCheckPath = dirToCheck / fileToCheck;
            return fs::exists(fileCheckPath);
        }
        return false;
    }

    void FileSystemHandler::GetDirectoryStructure(fs::path dirToCheck, std::vector<fs::path> &pathsInCurrentDirectory) {
        if(fs::exists(dirToCheck) && fs::is_directory(dirToCheck)){
            for(const fs::directory_entry& dirEntry : fs::directory_iterator(dirToCheck)){
                pathsInCurrentDirectory.push_back(dirEntry.path());
            }
        }
    }

    void FileSystemHandler::GetEntireDirectoryStructure(fs::path dirToCheck,
                                                        std::vector<fs::path> &allPathsInCurrentDirectory) {
        if(fs::exists(dirToCheck) && fs::is_directory(dirToCheck)){
            for(const fs::directory_entry& dirEntry : fs::recursive_directory_iterator(dirToCheck)){
                allPathsInCurrentDirectory.push_back(dirEntry.path());
            }
        }
    }
} // GLC