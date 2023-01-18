#include "logger.hpp"

Logger::Logger(const std::string& fileName, const int& maxFile, const int& frequency)
        :logFileName(fileName), maxFile(maxFile), frequency(frequency) {}
Logger::~Logger() {}
void Logger::log(std::string& message){
    logFile.open(logFileName, std::ios::app);
}
