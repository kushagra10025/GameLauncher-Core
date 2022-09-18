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
        void GetAllArchiveFile(std::filesystem::path& archivePath, std::vector<std::filesystem::path>& archiveFiles);
        // TODO Create Archive
        // TODO Append Archive
    };

} // GLC

#endif //GAMELAUNCHER_CORE_ARCHIVEHANDLER_H
