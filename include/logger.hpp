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
#include <future>
#include <queue>
#include <cstdio>
#include "CurrentPath.hpp"
#include "Colors.h"
#include "LogFrequency.hpp"
#include "LogLevel.hpp"

#define sleep(X) std::this_thread::sleep_for(X);

class Logger{
public:
    Logger( const int& maxFile=1,
            const LogFrequency& frequency = LogFrequency::Daily,
            const LogLevel& level = LogLevel::Undefined,
            const bool& printConsole = true);
    ~Logger();

    template<typename... Args>
    void log(const char* message, Args... args){  
        while(true){
            sleepLog();
            switch (m_level)
            {
                case LogLevel::Debug:
                    log("Debug", message);
                    if(m_isPrintable)
                        LOG_CYAN("[Debug]", message);
                break;

                case LogLevel::Error:
                    log("Error", message);
                    if(m_isPrintable)
                        LOG_RED("[Error]", message);
                break;

                case LogLevel::Info:
                    log("Info", message);
                    if(m_isPrintable)
                        LOG_GREEN("[Info]", message);
                break;
        
                default: 
                    log("Warn", message);
                    if(m_isPrintable)
                       LOG_YELLOW("[Warn]", message);
                break;
            }
        }
    }

    /* Setter Methods */
    void            setMaxFile(const int& maxFile);
    void            setFrequency(const LogFrequency& frequency);
    void            setLevel(const LogLevel& level);
    void            setIsPrintable(const bool& printConsole);

private:
    int                         m_maxFile;
    int                         m_countFiles;
    LogFrequency                m_frequency;
    LogLevel                    m_level;
    bool                        m_isPrintable;
    std::ofstream               m_logFile;
    CurrentPath*                m_curr;
    std::queue<std::string>     m_files;

    std::string     getUTCDate();
    void            sleepLog();
    void            log(const char* logType, const char* message);
    int             getCountOfLogs();
};
#endif