#pragma once

// service
#include "ServiceOneImpl.hpp"

// deps
#include <crow.h>


class ServiceOneAgent {
public:
    ServiceOneAgent(crow::SimpleApp& app) : _app{app} {

        CROW_ROUTE(app, "/")([this](){
            return _impl.index();
        });

        CROW_ROUTE(app, "/health")([this](){
            return _impl.health();
        });

        CROW_ROUTE(app, "/info")([this](){
            return _impl.info();
        });
    }
private:
    crow::SimpleApp& _app;
    ServiceOneImpl _impl;
};