#ifndef logger_hpp
#define logger_hpp
#include <iostream>
#include <fstream>
#include <ctime>

class Logger{
public:
    Logger(const std::string& fileName, const int& maxFile, const int& frequency);
    ~Logger();
    void log(std::string& message);


private:
    std::string logFileName;
    int maxFile;
    int frequency;
    std::ofstream logFile;
};

#endif