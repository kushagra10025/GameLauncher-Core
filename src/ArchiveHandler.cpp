//
// Created by Kushagra on 18-09-2022.
//

#include "ArchiveHandler.h"

namespace GLC {
    void ArchiveHandler::GetAllArchiveFile(std::filesystem::path& archivePath, std::vector<std::filesystem::path>& archiveFiles) {
        Archive* archive = zip_open(archivePath.string().c_str(),0, 'r');
        {
            ssize_t n = zip_entries_total(archive);
            for(ssize_t i = 0; i < n; ++i){
                zip_entry_openbyindex(archive, i);
                {
                    archiveFiles.emplace_back(zip_entry_name(archive));
                }
            }
        }
        zip_close(archive);
    }

} // GLC