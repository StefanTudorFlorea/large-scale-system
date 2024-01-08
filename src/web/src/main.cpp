// service
#include "ServiceWebAgent.hpp"
#include "utils.hpp"

// deps
#include <crow.h>
#include <string>
#include <fmt/core.h>
#include <httplib.h>
#include <yaml-cpp/yaml.h>

int main() {
    // crow::SimpleApp app;
    // ServiceWebAgent serviceAgent{app};
    // app.port(8080).multithreaded().run();
    // app.port(std::stoi(getenv("web.port"))).multithreaded().run();

    YAML::Node config = YAML::LoadFile("config.yml");;


    std::string serviceOne = utils::getEnvVarOrVal("web.ServiceOne.endpoint", config["endpoints"]["serviceOne"].as<std::string>());
    fmt::print("ServiceOne: {}", serviceOne);
    return 0;

    httplib::Client client{serviceOne};

    if (auto res = client.Get("/")) {
        if (res->status == 200) {
            fmt::print("Body: {}", res->body);
        }
    } else {
        auto err = res.error();
        fmt::print("[ERROR]: {}", httplib::to_string(err));
  }
}