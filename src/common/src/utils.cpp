#include "utils.hpp"

namespace utils {

std::string getEnvVarOrVal(const std::string& envVar, const std::string& val) {
    const char* env = std::getenv(envVar.c_str());
    if (!env) {
        return val;
    }
    return env;
}

} // ns utils