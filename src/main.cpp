#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <argparse/argparse.hpp>
#include <nlohmann/json.hpp>

#include "FileSystemHandler.h"
#include "JSONParseHandler.h"

void print_paths(std::vector<std::filesystem::path> to_print){
    for(auto print : to_print){
        std::cout << "==[ " << print.string() << " ]==" << std::endl;
    }
}

void print_entry_status(std::filesystem::file_status s)
{
    switch(s.type())
    {
        case std::filesystem::file_type::none: std::cout << " has `not-evaluated-yet` type"; break;
        case std::filesystem::file_type::not_found: std::cout << " does not exist"; break;
        case std::filesystem::file_type::regular: std::cout << " is a regular file"; break;
        case std::filesystem::file_type::directory: std::cout << " is a directory"; break;
        case std::filesystem::file_type::symlink: std::cout << " is a symlink"; break;
        case std::filesystem::file_type::block: std::cout << " is a block device"; break;
        case std::filesystem::file_type::character: std::cout << " is a character device"; break;
        case std::filesystem::file_type::fifo: std::cout << " is a named IPC pipe"; break;
        case std::filesystem::file_type::socket: std::cout << " is a named IPC socket"; break;
        case std::filesystem::file_type::unknown: std::cout << " has `unknown` type"; break;
        default: std::cout << " has `implementation-defined` type"; break;
    }
}

int main(int argc, char* argv[]) {
//
//    std::cout << "Added Libraries : " << std::endl;
//    std::cout << "\t1. Argparse\n\t2. Nlohmann JSON\n\t3. std::filesystem" << std::endl;

    GLC::FileSystemHandler fileSystemHandler;

//    std::string initPath = "E:\\Libraries";
//    std::filesystem::path pathToShow(initPath);

//    SHA256 Test
//    std::string versionFile = "E:\\Libraries\\version.json";
//    std::filesystem::path versionFilePath(versionFile);
//    if(fileSystemHandler.GetSHA256File(versionFilePath).has_value())
//        std::cout << fileSystemHandler.GetSHA256File(versionFilePath).value();
//    else
//        std::cout << "Couldn't Create SHA-256";
//    std::cout << "\n\n";

    std::string originalFolder = "E:\\DIffTestingFolder\\Original_Simple";
    std::filesystem::path originalPath(originalFolder);
    std::string updatedFolder = "E:\\DIffTestingFolder\\Update_Simple";
    std::filesystem::path updatedPath(updatedFolder);

    std::cout << originalPath.string() << std::endl;
    std::vector<std::filesystem::path> entireOriginalPathStruct;
    fileSystemHandler.GetEntireDirectoryStructure(originalPath, entireOriginalPathStruct);
    print_paths(entireOriginalPathStruct);
    std::cout << std::endl;

    std::cout << updatedPath.string() << std::endl;
    std::vector<std::filesystem::path> entireUpdatedPathStruct;
    fileSystemHandler.GetEntireDirectoryStructure(updatedPath, entireUpdatedPathStruct);
    print_paths(entireUpdatedPathStruct);
    std::cout << std::endl;

    std::cout << "\n\nCommon Files\n";
    std::vector<std::filesystem::path> commonFiles;
    fileSystemHandler.GetCommonFilesInDirectories(originalPath, updatedPath, commonFiles);
    print_paths(commonFiles);
    // For Common File Paths, as the File Names are same, then Relative File Paths are Not an Issue

    std::cout << "\n\nAdded Files\n";
    std::vector<std::filesystem::path> addedFiles;
    fileSystemHandler.GetDiffFilesInDirectory(updatedPath, originalPath, addedFiles);
    print_paths(addedFiles);
    // For Added Files Paths, as we need to Provide them separately their Absolute File Paths are Required

    std::cout << "\n\nRemoved Files\n";
    std::vector<std::filesystem::path> removedFiles;
    fileSystemHandler.GetDiffFilesInDirectory(originalPath, updatedPath, removedFiles);
    print_paths(removedFiles);
    // For Removed Files Paths, as we need to Remove them separately their Absolute File Paths are Required
    // Catch here is, The Files will be removed only on Client and not on Dev System
    // TODO Try to Solve the issue with the above mentioned catch.

    std::cout << "\n\nModified Files\n";
    std::vector<std::filesystem::path> modifiedFiles;
    fileSystemHandler.GetModifiedFiles(updatedPath, originalPath, modifiedFiles);
    print_paths(modifiedFiles);

    std::cout << "\n\n";


//    std::cout << "Entire Directory Structure\n";
//    std::vector<fs::path> allPathsInDirectory;
//    fileSystemHandler.GetEntireDirectoryStructure(pathToShow, allPathsInDirectory);
//    print_paths(allPathsInDirectory);
//
//    std::cout << "\n\nCurrent Directory Structure\n";
//    std::vector<fs::path> pathsInDirectory;
//    fileSystemHandler.GetDirectoryStructure(pathToShow, pathsInDirectory);
//    print_paths(pathsInDirectory);
//
//    std::cout << "\n\nCheck if File \"version.json\" exists in Directory\n";
//    std::cout << std::boolalpha;
//    bool versionFileExistence = fileSystemHandler.DoesFileExistInDirectory(pathToShow, "version.json");
//    std::cout << versionFileExistence << std::endl;
//
//    if(versionFileExistence){
//        JSONParseHandler jsonPraseHandler(pathToShow/"version.json");
//        std::cout << std::endl;
//        std::cout << std::setw(4) << jsonPraseHandler.getJSONFile() << std::endl;
//        std::cout << std::endl;
//
//        auto keyValue = jsonPraseHandler.getKey<std::string>("version");
//        std::cout << keyValue.value_or("Version Key Doesn't Exist") << std::endl;
//    }

    return 0;
}
