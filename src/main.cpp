#include <iostream>
#include <fstream>
#include <filesystem>
#include <argparse/argparse.hpp>
#include <nlohmann/json.hpp>

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

void get_entire_directory_structure(std::filesystem::path& pathToShow){
    if(std::filesystem::exists(pathToShow) && std::filesystem::is_directory(pathToShow)){
        for(const auto& entry : std::filesystem::recursive_directory_iterator(pathToShow)){
            auto pathname = entry.path().string();

            std::cout << pathname << " - ";
            print_entry_status(entry.status());
            std::cout << '\n';
        }
    }
}

void get_directory_structure(std::filesystem::path& pathToShow){
    if(std::filesystem::exists(pathToShow) && std::filesystem::is_directory(pathToShow)){
        for(const auto& entry: std::filesystem::directory_iterator(pathToShow)){
            auto pathname = entry.path().string();
            std::cout << pathname << " - ";
            print_entry_status(entry.status());
            std::cout << "\n";
        }
    }
}

bool does_file_exist_in_directory(std::filesystem::path dirToCheck, std::string fileName){
    std::filesystem::path fileToCheck = dirToCheck / fileName;
    return std::filesystem::exists(fileToCheck);
}

int main(int argc, char* argv[]) {
//
//    std::cout << "Added Libraries : " << std::endl;
//    std::cout << "\t1. Argparse\n\t2. Nlohmann JSON\n\t3. std::filesystem" << std::endl;

    std::string initPath = "E:\\Libraries";
    std::filesystem::path pathToShow(initPath);

//    get_entire_directory_structure(pathToShow);
    get_directory_structure(pathToShow);
    std::cout << std::boolalpha << does_file_exist_in_directory(pathToShow, "version.json");
    std::cout << std::endl;

    if(does_file_exist_in_directory(pathToShow, "version.json")){
        std::string filePath = (pathToShow/"version.json").string();
        std::ifstream file(filePath);
        nlohmann::json dt = nlohmann::json::parse(file);
        std::cout << std::setw(4) << dt << std::endl;
        std::cout << std::endl;
        auto vrsn = dt["version"].get<std::string>();
        std::cout << vrsn << std::endl;
    }
    return 0;
}
