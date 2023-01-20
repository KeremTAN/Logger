#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <iostream>
#include <fstream>
#include <ctime>

class Logger{
public:
    Logger(const std::string& fileName, const int& maxFile, const int& frequency);
    ~Logger();
    void log(const std::string& message);


private:
    std::string logFileName;
    int maxFile;
    int frequency;
    std::ofstream logFile;
};
#endif