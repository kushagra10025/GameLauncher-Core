//
// Created by Kushagra on 08-09-2022.
//

#ifndef GAMELAUNCHER_CORE_FILESYSTEMHANDLER_H
#define GAMELAUNCHER_CORE_FILESYSTEMHANDLER_H

#include <filesystem>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;
namespace GLC {

    class FileSystemHandler {
    public:
        FileSystemHandler();

        bool DoesFileExistInDirectory(fs::path dirToCheck, std::string fileToCheck);
        void GetDirectoryStructure(fs::path dirToCheck, std::vector<fs::path>& pathsInCurrentDirectory);
        void GetEntireDirectoryStructure(fs::path dirToCheck, std::vector<fs::path>& allPathsInCurrentDirectory);

        /// Get Common Files in DirA and DirB
        /// \param dirA DirectoryA
        /// \param dirB DirectoryB
        /// \param commonFiles Returns all Relative Common file paths in DirA and DirB
        void GetCommonFilesInDirectories(const fs::path& dirA, const fs::path& dirB, std::vector<fs::path>& commonFiles);

        /// Get Files which are present in DirA but not in DirB
        /// \param dirA DirectoryA
        /// \param dirB DirectoryB
        /// \param addedFiles Returns all Relative Diff file paths in DirA which are absent from DirB
        void GetDiffFilesInDirectory(const fs::path& dirA, const fs::path& dirB, std::vector<fs::path>& diffFiles);

        // TODO Get Modified Files -> From All Common Files, get the Modified Files

        /// Get Only File paths in the directory
        /// \param dirA DirectoryA
        /// \param filePaths Returns all FilePaths in DirA
        void GetFilePathsInDirectory(const fs::path& dirA, std::vector<fs::path>& filePaths);

        /// Get all Files paths relative to base
        /// \param base Base
        /// \param filePaths Return File Paths Relative to Base
        void GetRelativePaths(const fs::path& base, std::vector<fs::path>& filePaths);

        /// Get all Files paths absolute with base
        /// \param base Base
        /// \param filePaths Return File Paths Absolute with Base
        void GetAbsolutePaths(const fs::path& base, std::vector<fs::path>& filePaths);
    };

} // GLC

#endif //GAMELAUNCHER_CORE_FILESYSTEMHANDLER_H
