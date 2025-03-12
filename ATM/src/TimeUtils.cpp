#include "TimeUtils.hpp"
#include <sstream>
#include <iomanip>
#include <ctime>

std::string getCurrentTime() {
    std::ostringstream oss;
    std::time_t now = std::time(nullptr);
    oss << std::put_time(std::localtime(&now), "%Y-%m-%d %H:%M:%S");
    return oss.str();
}