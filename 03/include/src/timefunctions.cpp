#include "TimeFunctions.h"
#include <ctime>
#include <sstream>
#include <string>
#include <iomanip>

// #05 Function - void getTime()
// When called, provides the date and time via reference parameters.
void getTime(std::string &dateTime) {
    time_t now = time(nullptr);
    tm localTime;
    #if defined(_WIN32) || defined(_WIN64)
    localtime_s(&localTime, &now);
    #else
    localTime = *localtime(&now);
    #endif

    char buffer[100];
    strftime(buffer, 100, "%Y-%m-%d %H:%M:%S", &localTime);
    dateTime = buffer;
}
