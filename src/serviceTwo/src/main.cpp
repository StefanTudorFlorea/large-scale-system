// service
#include "ServiceTwoAgent.hpp"

// deps
#include <crow.h>
#include <fmt/core.h>

int main() {
    crow::SimpleApp app;

    ServiceTwoAgent serviceAgent{app};

    app.port(std::stoi(getenv("ServiceTwo.port"))).multithreaded().run();
}