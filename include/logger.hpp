#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <iostream>
#include <fstream>
#include <ctime>
#include <dirent.h>

class Logger{
public:
    Logger(const std::string& fileName, const int& maxFile, const int& frequency);
    ~Logger();
    std::string getUTCDate();
    int getCountOfLogs();
    void log(const std::string& message);

private:
    std::string logFileName;
    int maxFile;
    int frequency;
    std::ofstream logFile;
};
#endif