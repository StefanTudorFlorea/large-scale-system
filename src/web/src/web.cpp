// utils
#include "utils.hpp"

// deps
#include <crow.h>
#include <fmt/core.h>
#include <httplib.h>
#include <string>
#include <yaml-cpp/yaml.h>

std::string queryService(const std::string& endpoint) {

    httplib::Client client{endpoint};
    std::string response;

    if (auto res = client.Get("/")) {
        if (res->status == 200) {
            response = res->body;
        }
    } else {
        auto err = res.error();
        response = httplib::to_string(err);
  }

  return response;
}

std::string getServices() {
    YAML::Node config = YAML::LoadFile("config.yml");

    std::string gatewayEndpoint = utils::getEnvVarOrVal("web.gateway.endpoint", config["endpoints"]["gateway"].as<std::string>());

    std::string serviceOneEndpoint = gatewayEndpoint + "/serviceOne";
    std::string serviceTwoEndpoint = gatewayEndpoint + "/serviceTwo";
    std::string serviceTreEndpoint = gatewayEndpoint + "/serviceTre";

    return fmt::format("ServiceOne: {}\nServiceTwo: {}\nServiceTre: {}\n", 
        queryService(serviceOneEndpoint), 
        queryService(serviceTwoEndpoint),
        queryService(serviceTreEndpoint)
    );
}

int main() {
    crow::SimpleApp app;
    YAML::Node config = YAML::LoadFile("config.yml");

    CROW_ROUTE(app, "/")([](){
        return getServices();
    });

    app.port(std::stoi(utils::getEnvVarOrVal("web.port", config["web"]["port"].as<std::string>()))).multithreaded().run();
}