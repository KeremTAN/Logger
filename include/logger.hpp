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
#include "Colors.h"

enum class LogType
{
    Critical, Debug, Error, Info, Warn, Trace
};

class Logger{
public:
    Logger(const int& maxFile, const int& frequency, const bool& printConsole = 1);
    ~Logger();

    template<typename... Args>
    void Warn(const char* message, Args... args){
        log("Warn", message);
        if(m_printConsole)
            LOG_YELLOW("[Warn]", message);
    }

    template<typename... Args>
    void Error(const char* message, Args... args){
        log("Error", message);
        if(m_printConsole)
            LOG_RED("[Error]", message);
    }
    
    template<typename... Args>
    void Info(const char* message, Args... args){
        log("Info", message);
        if(m_printConsole)
            LOG_GREEN("[Info]", message);
    }

    template<typename... Args>
    void Debug(const char* message, Args... args){
        log("Debug", message);
        if(m_printConsole)
            LOG_CYAN("[Debug]", message);
    }

private:
    int             m_maxFile;
    int             m_frequency;
    bool            m_printConsole;
    std::ofstream   m_logFile;
    CurrentPath*    m_curr;
    
    std::string getUTCDate();
    int getCountOfLogs();
    void log(const char* logType, const char* message);
};
#endif