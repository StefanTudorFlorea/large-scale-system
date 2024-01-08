#pragma once
#include <crow.h>
#include <yaml-cpp/yaml.h>

class ServiceThreeImpl {
public:
    ServiceThreeImpl() {
        _config = YAML::LoadFile("config.yml");
    }

    crow::response index() {
        return "Hello from " + _config["info"]["name"].as<std::string>();
    }

    crow::response health() {
        return crow::response(crow::status::OK);
    }

    crow::json::wvalue info() {

        return {
            {"version",     _config["info"]["version"].as<std::string>()},
            {"environment", _config["info"]["environment"].as<std::string>()},
            {"name",        _config["info"]["name"].as<std::string>()}
        };
    }
private:
    YAML::Node _config;
};