// service
#include "ServiceWebAgent.hpp"

// deps
#include <crow.h>
#include <fmt/core.h>

int main() {
    crow::SimpleApp app;

    ServiceWebAgent serviceAgent{app};

    app.port(std::stoi(getenv("web.port"))).multithreaded().run();
}