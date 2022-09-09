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

    void FileSystemHandler::GetCommonFilesInDirectories(const fs::path& dirA, const fs::path& dirB, std::vector<fs::path> &commonFiles) {
        // TODO Try to Execute in Parallel
        std::vector<fs::path> filesInDirA;
        GetFilePathsInDirectory(dirA, filesInDirA);
        GetRelativePaths(dirA, filesInDirA);
        // TODO Try to Execute in Parallel
        std::vector<fs::path> filesInDirB;
        GetFilePathsInDirectory(dirB, filesInDirB);
        GetRelativePaths(dirB, filesInDirB);

        std::sort(filesInDirA.begin(), filesInDirA.end());
        std::sort(filesInDirB.begin(), filesInDirB.end());

        std::set_intersection(filesInDirA.begin(), filesInDirA.end(),
                              filesInDirB.begin(), filesInDirB.end(),
                              std::inserter(commonFiles, commonFiles.begin()));
    }

    void FileSystemHandler::GetDiffFilesInDirectory(const fs::path& dirA, const fs::path& dirB, std::vector<fs::path> &diffFiles) {
        // TODO Try to Execute in Parallel
        std::vector<fs::path> filesInDirA;
        GetFilePathsInDirectory(dirA, filesInDirA);
        GetRelativePaths(dirA, filesInDirA);
        // TODO Try to Execute in Parallel
        std::vector<fs::path> filesInDirB;
        GetFilePathsInDirectory(dirB, filesInDirB);
        GetRelativePaths(dirB, filesInDirB);

        std::sort(filesInDirA.begin(), filesInDirA.end());
        std::sort(filesInDirB.begin(), filesInDirB.end());

        std::set_difference(filesInDirA.begin(), filesInDirA.end(),
                            filesInDirB.begin(), filesInDirB.end(),
                            std::inserter(diffFiles, diffFiles.begin()));
    }

    void FileSystemHandler::GetFilePathsInDirectory(const fs::path &dirA, std::vector<fs::path> &filePaths) {
        GetEntireDirectoryStructure(dirA, filePaths);
        // From the Entire Directory Structure remove all paths which are directory
        filePaths.erase(std::remove_if(filePaths.begin(), filePaths.end(),
                                       [](const fs::path& fP){return fs::is_directory(fP);}),
                        filePaths.end());
    }

    void FileSystemHandler::GetRelativePaths(const fs::path &base, std::vector<fs::path> &filePaths) {
        for(auto& filePath : filePaths){
            filePath = fs::relative(filePath, base);
        }
    }

    void FileSystemHandler::GetAbsolutePaths(const fs::path &base, std::vector<fs::path> &filePaths) {
        for(auto& filePath : filePaths){
            filePath = base / filePath;
        }
    }
} // GLC