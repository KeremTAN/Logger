#include "Logger.hpp"
#include "fstream"

Logger::Logger(const std::string& fileName, const int& maxFile, const int& frequency)
        :logFileName(fileName), maxFile(maxFile), frequency(frequency) {}
Logger::~Logger() {}

void Logger::log(const std::string& message){
        logFile.open(logFileName, std::ios::app);
        // Get current time
        time_t now = time(0);
        struct tm tstruct;
        char buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);

        // Write the log message to file
        logFile << "[" << buf << "] " << message << std::endl;

        // Close the log file
        logFile.close();

        // Check if the number of log files exceeds the max limit
        // and delete the oldest log file
        if (maxFile > 0) {
            // Code to check the number of log files and delete the oldest one
        }
}
