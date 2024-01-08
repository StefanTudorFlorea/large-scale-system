#pragma once

#include <string>

namespace utils {
    
std::string getEnvVarOrVal(const std::string& envVar, const std::string& val);

} // ns utils
