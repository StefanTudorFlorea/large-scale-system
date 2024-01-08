// service
#include "ServiceTreAgent.hpp"

// deps
#include <crow.h>
#include <fmt/core.h>

int main() {
    crow::SimpleApp app;

    ServiceTreAgent serviceAgent{app};

    app.port(std::stoi(getenv("serviceTre.port"))).multithreaded().run();
}