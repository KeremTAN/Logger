#include "Logger.hpp"

Logger::Logger(const std::string& fileName, const int& maxFile, const int& frequency)
        :logFileName(fileName), maxFile(maxFile), frequency(frequency) {}
Logger::~Logger() {}

std::string Logger::getUTCDate(){
        time_t now = time(0);
        struct tm tstruct;
        tstruct = *gmtime(&now);

        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d_%X", &tstruct);

        std::string date=buf;
        return date;
}

int Logger::getCountOfLogs(){
        DIR *dir;
        struct dirent *ent;
        int file_count = 0;
        if ((dir = opendir ("/path/to/folder")) != NULL) {
                while ((ent = readdir (dir)) != NULL) {
                        if (ent->d_type == DT_REG) { // d_type == DT_REG is a regular file
                                file_count++;
                        }
                }
                closedir (dir);
        } 
        else {
                perror ("");
                return EXIT_FAILURE;
        }
    return file_count;
}

void Logger::log(const std::string& message){
        std::string filePath= "logs/"+getUTCDate()+".log"; 
        logFile.open(filePath, std::ios::app); 

        // Write the log message to file 
        logFile << "[" << getUTCDate() << "] " << message << std::endl;

        // Close the log file
        logFile.close();

        // Check if the number of log files exceeds the max limit
        // and delete the oldest log file
        if (maxFile > 0) {
            // Code to check the number of log files and delete the oldest one
        }
}
