#include "logging.hpp"
#include <fstream>
#include <iostream>
#include <string>

logging::logging(std::string file_name) {
    std::fstream log;
    logFile = file_name;
    log.open(logFile.c_str());
    log << "Document Data Store Logs: " << std::endl;
    log.close();
}

void logging::newLog(std::string logText) {
    std::fstream log;
    log.open(logFile.c_str(), std::ios::app);
    if (!log) {
        log.open(logFile.c_str());
        log << logText << std::endl;
        log.close();
    } else {
        log << logText << std::endl;
        log.close();
    }
}
