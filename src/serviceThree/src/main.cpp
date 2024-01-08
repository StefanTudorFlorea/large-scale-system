// service
#include "ServiceThreeAgent.hpp"

// deps
#include <crow.h>
#include <fmt/core.h>

int main() {
    crow::SimpleApp app;

    ServiceThreeAgent serviceAgent{app};

    app.port(std::stoi(getenv("serviceThree.port"))).multithreaded().run();
}