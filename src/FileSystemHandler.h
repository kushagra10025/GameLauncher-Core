//
// Created by Kushagra on 08-09-2022.
//

#ifndef GAMELAUNCHER_CORE_FILESYSTEMHANDLER_H
#define GAMELAUNCHER_CORE_FILESYSTEMHANDLER_H

#include <filesystem>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <optional>

namespace fs = std::filesystem;
namespace GLC {

    class FileSystemHandler {
    public:
        FileSystemHandler();

        bool DoesFileExistInDirectory(fs::path dirToCheck, std::string fileToCheck);
        void GetDirectoryStructure(fs::path dirToCheck, std::vector<fs::path>& pathsInCurrentDirectory);
        void GetEntireDirectoryStructure(fs::path dirToCheck, std::vector<fs::path>& allPathsInCurrentDirectory);

        void GetCommonFilesInDirectories(const fs::path& dirA, const fs::path& dirB, std::vector<fs::path>& commonFiles);
        void GetDiffFilesInDirectory(const fs::path& dirA, const fs::path& dirB, std::vector<fs::path>& diffFiles);

        // TODO Get Modified Files -> From All Common Files, get the Modified Files
        void GetModifiedFiles(const fs::path& dirA, const fs::path& dirB, std::vector<fs::path>& modifiedFiles);

        void GetFilePathsInDirectory(const fs::path& dirA, std::vector<fs::path>& filePaths);
        void GetRelativePaths(const fs::path& base, std::vector<fs::path>& filePaths);
        void GetAbsolutePaths(const fs::path& base, std::vector<fs::path>& filePaths);

        std::optional<std::string> GetSHA256File(const fs::path& filePath);
    };

} // GLC

#endif //GAMELAUNCHER_CORE_FILESYSTEMHANDLER_H
