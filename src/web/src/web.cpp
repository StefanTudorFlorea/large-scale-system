// service
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

    fmt::print("\nService endpoint:", endpoint);

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
    YAML::Node config = YAML::LoadFile("config.yml");;

    std::string serviceOneEndpoint = utils::getEnvVarOrVal("web.serviceOne.endpoint", config["endpoints"]["serviceOne"].as<std::string>());
    std::string serviceTwoEndpoint = utils::getEnvVarOrVal("web.serviceTwo.endpoint", config["endpoints"]["serviceTwo"].as<std::string>());
    std::string serviceThreeEndpoint = utils::getEnvVarOrVal("web.serviceThree.endpoint", config["endpoints"]["serviceThree"].as<std::string>());

    return fmt::format("ServiceOne: {}\nServiceTwo: {}\nServiceThree: {}\n", 
        queryService(serviceOneEndpoint), 
        queryService(serviceTwoEndpoint),
        queryService(serviceThreeEndpoint)
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