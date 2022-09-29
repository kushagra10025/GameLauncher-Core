//
// Created by Kushagra on 18-09-2022.
//

#ifndef GAMELAUNCHER_CORE_ARCHIVEHANDLER_H
#define GAMELAUNCHER_CORE_ARCHIVEHANDLER_H

#include <iostream>
#include <filesystem>
#include <kubazip/zip.h>

typedef zip_t Archive;

namespace GLC {

    class ArchiveHandler {
    public:
        void GetAllFilesInArchive(std::filesystem::path& archivePath, std::vector<std::filesystem::path>& archiveFiles);
        void CreateArchiveFromFolder(const std::filesystem::path& archivePath, const std::vector<std::filesystem::path>& entireDirectoryStructure);
        void CreateArchiveFromSingleFile(const std::filesystem::path& archivePath, const std::filesystem::path& fileToAddToArchive);
        void AppendFolderToArchive(const std::filesystem::path& archivePath, const std::vector<std::filesystem::path>& appendDirectoryStructure);
        void AppendFileToArchive(const std::filesystem::path& archivePath, const std::filesystem::path& fileToAppendToArchive);
    };

} // GLC

#endif //GAMELAUNCHER_CORE_ARCHIVEHANDLER_H
