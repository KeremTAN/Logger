#include "Logger.hpp"
#include "Colors.h"


Logger::Logger(const std::string& fileName, const int& maxFile, const int& frequency)
        :m_logFileName(fileName), m_maxFile(maxFile), m_frequency(frequency) {
                m_curr=CurrentPath::getInstance();
        }

Logger::~Logger() {}

std::string Logger::getUTCDate(){
        time_t now = time(0);
        struct tm tstruct;
        tstruct = *gmtime(&now);

        char buf[80];
        strftime(buf, sizeof(buf), "%Y-%m-%d_%X", &tstruct);
        return buf;
}

int Logger::getCountOfLogs(){
        DIR *dir;
        struct dirent *ent;
        int file_count = 0;
        std::string path = m_curr->getPath()+"/logs/";
        if ((dir = opendir (path.c_str())) != NULL) {
                while ((ent = readdir (dir)) != NULL) {
                        if (ent->d_type == DT_REG) {
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
        m_logFile.open(filePath, std::ios::app); 

        // Write the log message to file 
        m_logFile << "[" << getUTCDate() << "] " << message << std::endl;

        // Close the log file
        m_logFile.close();
        LOG_RED("[Debug] : ", message.c_str());
        // Check if the number of log files exceeds the max limit
        // and delete the oldest log file
       // std::cout <<m_logType<<'\n';
        if (m_maxFile > 0) {
            std::cout<<getCountOfLogs();
        }
}

LogType Logger::m_logType=LogType::Warn;
void Logger::setLogType(const LogType& logType){
        m_logType=logType;
}
