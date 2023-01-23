#include "Logger.hpp"

Logger::Logger(const std::string& fileName, const int& maxFile, const int& frequency)
        :logFileName(fileName), maxFile(maxFile), frequency(frequency) {}
Logger::~Logger() {}

void Logger::log(const std::string& message){
        time_t now = time(0);
        struct tm tstruct;
        tstruct = *gmtime(&now);

        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d_%X", &tstruct);

        std::string date=buf;
        std::string filePathAndName = "logs/"+date+".log"; 
   

        logFile.open(filePathAndName, std::ios::app); 

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
