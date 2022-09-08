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

std::optional<std::string> JSONPraseHandler::getStringKey(const std::string& key) const {
    if(!isJSONFileValid() && !isJSONKeyValid(key)) return std::nullopt;
    std::string value = jsonFile[key].get<std::string>();
    return std::optional<std::string>{value};
}

std::optional<int32_t> JSONPraseHandler::getIntKey(const std::string &key) const {
    if(!isJSONFileValid() && !isJSONKeyValid(key)) return std::nullopt;
    int32_t value = jsonFile[key].get<int32_t>();
    return std::optional<int32_t>{value};
}

std::optional<double> JSONPraseHandler::getDoubleKey(const std::string &key) const {
    if(!isJSONFileValid() && !isJSONKeyValid(key)) return std::nullopt;
    double value = jsonFile[key].get<double>();
    return std::optional<double>{value};
}

std::optional<bool> JSONPraseHandler::getBoolKey(const std::string &key) const {
    if(!isJSONFileValid() && !isJSONKeyValid(key)) return std::nullopt;
    double value = jsonFile[key].get<double>();
    return std::optional<bool>{value};
}

bool JSONPraseHandler::isJSONFileValid() const {
    if(!jsonFile.empty()) return true;
    else return false;
}

bool JSONPraseHandler::isJSONKeyValid(const std::string& key) const {
    // Throws Assertion Error -> use at() [at() -> returns value_type]
    if(!jsonFile.contains(key)) return false;
    else return true;
}

nlohmann::json JSONPraseHandler::getJSONPatch(nlohmann::json checkDiffAgainst) {
    return nlohmann::json::diff(checkDiffAgainst, jsonFile);
}

void JSONPraseHandler::applyJSONPatch(nlohmann::json patch) {
    jsonFile.patch(patch);
}


