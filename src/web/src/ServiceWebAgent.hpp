#pragma once

// service
#include "ServiceWebImpl.hpp"

// deps
#include <crow.h>


class ServiceWebAgent {
public:
    ServiceWebAgent(crow::SimpleApp& app) : _app{app} {

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
    ServiceWebImpl _impl;
};