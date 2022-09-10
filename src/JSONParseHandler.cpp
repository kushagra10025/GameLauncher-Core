//
// Created by Kushagra on 08-09-2022.
//

#include <fstream>
#include <iostream>
#include "JSONParseHandler.h"

JSONParseHandler::JSONParseHandler(std::filesystem::path pathToVersionFile) {
    std::ifstream VersionFileData(pathToVersionFile.string());
    jsonFile = nlohmann::json::parse(VersionFileData);
}

nlohmann::json JSONParseHandler::getJSONFile() const {
    return jsonFile;
}

bool JSONParseHandler::isJSONFileValid() const {
    if(!jsonFile.empty()) return true;
    else return false;
}

bool JSONParseHandler::isJSONKeyValid(const std::string& key) const {
    // Throws Assertion Error -> use at() [at() -> returns value_type]
    bool isKeyValid = false;
    try {
        jsonFile.at(key);
        isKeyValid = true;
    }
    catch (const nlohmann::json::out_of_range& e) {
        isKeyValid = false;
    }

    return isKeyValid;
}

nlohmann::json JSONParseHandler::getJSONPatch(const nlohmann::json& checkDiffAgainst) {
    return nlohmann::json::diff(checkDiffAgainst, jsonFile);
}

void JSONParseHandler::applyJSONPatch(const nlohmann::json& patch) {
    jsonFile.patch(patch);
}
