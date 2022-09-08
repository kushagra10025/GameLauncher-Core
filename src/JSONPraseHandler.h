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

    template<typename T>
    std::optional<T> getKey(const std::string& key) const{
        if(!isJSONFileValid() || !isJSONKeyValid(key)) return std::nullopt;
        T value = jsonFile[key].get<T>();
        return std::optional<T>{value};
    }

    nlohmann::json getJSONPatch(const nlohmann::json& checkDiffAgainst);
    void applyJSONPatch(const nlohmann::json& patch);
};


#endif //GAMELAUNCHER_CORE_JSONPRASEHANDLER_H
