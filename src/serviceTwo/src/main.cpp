// service
#include "ServiceTwoAgent.hpp"
#include "utils.hpp"

// deps
#include <crow.h>
#include <fmt/core.h>
#include <yaml-cpp/yaml.h>


int main() {
    crow::SimpleApp app;
    YAML::Node config = YAML::LoadFile("config.yml");

    ServiceTwoAgent serviceAgent{app};

    app.port(std::stoi(utils::getEnvVarOrVal("serviceTwo.port", config["service"]["port"].as<std::string>()))).multithreaded().run();
}