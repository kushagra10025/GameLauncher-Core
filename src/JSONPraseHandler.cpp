//
// Created by Kushagra on 08-09-2022.
//

#include <fstream>
#include <iostream>
#include "JSONPraseHandler.h"

JSONPraseHandler::JSONPraseHandler(std::filesystem::path pathToVersionFile) {
    std::ifstream VersionFileData(pathToVersionFile.string());
    jsonFile = nlohmann::json::parse(VersionFileData);
}

nlohmann::json JSONPraseHandler::getJSONFile() const {
    return jsonFile;
}

bool JSONPraseHandler::isJSONFileValid() const {
    if(!jsonFile.empty()) return true;
    else return false;
}

bool JSONPraseHandler::isJSONKeyValid(const std::string& key) const {
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

nlohmann::json JSONPraseHandler::getJSONPatch(const nlohmann::json& checkDiffAgainst) {
    return nlohmann::json::diff(checkDiffAgainst, jsonFile);
}

void JSONPraseHandler::applyJSONPatch(const nlohmann::json& patch) {
    jsonFile.patch(patch);
}
