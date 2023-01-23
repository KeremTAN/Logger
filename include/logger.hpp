/**
 * @file Logger.hpp
 * @author Kerem TAN
 * @brief 
 * @version 0.1
 * @date 2023-01-23
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <iostream>
#include <fstream>
#include <ctime>
#include <dirent.h>
#include "CurrentPath.hpp"

enum class LogType
{
    Critical, Debug, Error, Info, Warn, Trace
};

class Logger{
public:
    Logger(const std::string& fileName, const int& maxFile, const int& frequency);
    ~Logger();
    std::string getUTCDate();
    int getCountOfLogs();
    void log(const std::string& message);
    static void setLogType(const LogType& logType);

private:
    std::string     m_logFileName;
    int             m_maxFile;
    int             m_frequency;
    std::ofstream   m_logFile;
    static LogType  m_logType;
    CurrentPath*    m_curr;
};
#endif