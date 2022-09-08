//
// Created by Kushagra on 08-09-2022.
//

#ifndef GAMELAUNCHER_CORE_JSONPRASEHANDLER_H
#define GAMELAUNCHER_CORE_JSONPRASEHANDLER_H

#include <nlohmann/json.hpp>
#include <optional>

class JSONPraseHandler {
private:
    nlohmann::json jsonFile;

    bool isJSONFileValid() const;
    bool isJSONKeyValid(const std::string& key) const;
public:
    JSONPraseHandler(std::filesystem::path pathToVersionFile);

    nlohmann::json getJSONFile() const;
    std::optional<std::string> getStringKey(const std::string& key) const;
    std::optional<int32_t> getIntKey(const std::string& key) const;
    std::optional<double> getDoubleKey(const std::string& key) const;
    std::optional<bool> getBoolKey(const std::string& key) const;

    nlohmann::json getJSONPatch(nlohmann::json checkDiffAgainst);
    void applyJSONPatch(nlohmann::json patch);
};


#endif //GAMELAUNCHER_CORE_JSONPRASEHANDLER_H
