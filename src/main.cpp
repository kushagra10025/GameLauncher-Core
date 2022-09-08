#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <argparse/argparse.hpp>
#include <nlohmann/json.hpp>

#include "FileSystemHandler.h"
#include "JSONPraseHandler.h"

void print_paths(std::vector<std::filesystem::path> to_print){
    for(auto print : to_print){
        std::cout << "..[ " << print.string() << " ].." << std::endl;
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

    std::string initPath = "E:\\Libraries";
    std::filesystem::path pathToShow(initPath);

    std::cout << "Entire Directory Structure\n";
    std::vector<fs::path> allPathsInDirectory;
    fileSystemHandler.GetEntireDirectoryStructure(pathToShow, allPathsInDirectory);
    print_paths(allPathsInDirectory);

    std::cout << "\n\nCurrent Directory Structure\n";
    std::vector<fs::path> pathsInDirectory;
    fileSystemHandler.GetDirectoryStructure(pathToShow, pathsInDirectory);
    print_paths(pathsInDirectory);

    std::cout << "\n\nCheck if File \"version.json\" exists in Directory\n";
    std::cout << std::boolalpha;
    bool versionFileExistence = fileSystemHandler.DoesFileExistInDirectory(pathToShow, "version.json");
    std::cout << versionFileExistence << std::endl;

    if(versionFileExistence){
        JSONPraseHandler jsonPraseHandler(pathToShow/"version.json");
        std::cout << std::endl;
        std::cout << std::setw(4) << jsonPraseHandler.getJSONFile() << std::endl;
        std::cout << std::endl;
        if (auto vrsn = jsonPraseHandler.getStringKey("version")) {
            std::cout << "create2(true) returned " << vrsn.value() << '\n';
        }else{
            std::cout << "Version Key Doesn't Exist" << std::endl;
        }
    }

    return 0;
}
