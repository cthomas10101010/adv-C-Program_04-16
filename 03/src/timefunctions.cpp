#include "TimeFunctions.h"
#include <ctime>
#include <string>

void getTime(std::string& timeStr) {
    time_t now = time(0);
    timeStr = ctime(&now);
    if (!timeStr.empty() && timeStr[timeStr.length()-1] == '\n') {
        timeStr = timeStr.substr(0, timeStr.length()-1);
    }
}