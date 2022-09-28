//
// Created by Kushagra on 18-09-2022.
//

#include "ArchiveHandler.h"

namespace GLC {
    void ArchiveHandler::GetAllFilesInArchive(std::filesystem::path& archivePath, std::vector<std::filesystem::path>& archiveFiles) {
        if(std::filesystem::is_directory(archivePath)){
            return; // Path is a directory
        }
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

    void ArchiveHandler::CreateArchiveFromFolder(const std::filesystem::path &archivePath, const std::vector<std::filesystem::path> &entireDirectoryStructure) {
        if(std::filesystem::is_directory(archivePath)){
            return; // Path is a directory
        }
        Archive* archive = zip_open(archivePath.string().c_str(), ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');
        {
            for(const auto& filePath : entireDirectoryStructure){
                // TODO Replace Code with Append Single File to Archive
                if(std::filesystem::is_directory(filePath)) continue;
                zip_entry_open(archive, std::filesystem::relative(filePath, filePath.root_path()).string().c_str());
                {
                    zip_entry_fwrite(archive, filePath.string().c_str());
                }
                zip_entry_close(archive);
            }
        }
        zip_close(archive);
    }

    void ArchiveHandler::CreateArchiveFromSingleFile(const std::filesystem::path &archivePath, const std::filesystem::path &fileToAddToArchive) {
        if(std::filesystem::is_directory(archivePath)){
            return; // Path is a directory
        }
        if(std::filesystem::is_directory(fileToAddToArchive)){
            return; // Path is a directory
        }
        Archive* archive = zip_open(archivePath.string().c_str(), ZIP_DEFAULT_COMPRESSION_LEVEL, 'w');
        {
            zip_entry_open(archive, std::filesystem::relative(fileToAddToArchive, fileToAddToArchive.root_path()).string().c_str());
            {
                zip_entry_fwrite(archive, fileToAddToArchive.string().c_str());
            }
            zip_entry_close(archive);
        }
        zip_close(archive);
    }

} // GLC