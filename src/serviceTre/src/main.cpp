// service
#include "ServiceTreAgent.hpp"
#include "utils.hpp"

// deps
#include <crow.h>
#include <fmt/core.h>
#include <yaml-cpp/yaml.h>


int main() {
    crow::SimpleApp app;
    YAML::Node config = YAML::LoadFile("config.yml");

    ServiceTreAgent serviceAgent{app};

    app.port(std::stoi(utils::getEnvVarOrVal("serviceTre.port", config["service"]["port"].as<std::string>()))).multithreaded().run();
}