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
#include <chrono>
#include<future>
#include "CurrentPath.hpp"
#include "Colors.h"
#include "LogFrequency.hpp"
#include "LogLevel.hpp"

#define sleep(X) std::this_thread::sleep_for(X);

class Logger{
public:
    Logger( const int& maxFile,
            const LogFrequency& frequency = LogFrequency::Daily,
            const LogLevel& level = LogLevel::Warn,
            const bool& printConsole = 1);
    ~Logger();

    template<typename... Args>
    void log(const char* message, Args... args){  
        while(1){
            sleepLog();
            switch (m_level)
            {
                case LogLevel::Debug:
                    log("Debug", message);
                    if(m_printConsole)
                        LOG_CYAN("[Debug]", message);
                break;

                case LogLevel::Error:
                    log("Error", message);
                    if(m_printConsole)
                        LOG_RED("[Error]", message);
                break;

                case LogLevel::Info:
                    log("Info", message);
                    if(m_printConsole)
                        LOG_GREEN("[Info]", message);
                break;
        
                default: 
                    log("Warn", message);
                    if(m_printConsole)
                       LOG_YELLOW("[Warn]", message);
                break;
            }
        }
    }
private:
    int             m_maxFile;
    LogFrequency    m_frequency;
    LogLevel        m_level;
    bool            m_printConsole;
    std::ofstream   m_logFile;
    CurrentPath*    m_curr;

    std::string getUTCDate();
    int getCountOfLogs();
    void sleepLog();
    void log(const char* logType, const char* message);
};
#endif