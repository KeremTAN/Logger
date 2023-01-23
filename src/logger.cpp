#include "Logger.hpp"

Logger::Logger(const int& maxFile, const LogFrequency& frequency, const LogLevel& level, const bool& printConsole)
        :m_maxFile(maxFile), m_frequency(frequency), m_level(level), m_printConsole(printConsole){
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

void Logger::log(const char* logType, const char* message){
        std::this_thread::sleep_for(std::chrono::seconds(20));
        //auto sleepTime = std::chrono::seconds(20);
        std::string filePath= "logs/"+getUTCDate()+".log"; 
        m_logFile.open(filePath, std::ios::app); 
        // Write the log message to file 
        m_logFile << "[" << getUTCDate() << "] " << message << std::endl;

        // Close the log file
        m_logFile.close();
       
        // Check if the number of log files exceeds the max limit
        // and delete the oldest log file
       // std::cout <<m_logType<<'\n';
        if (m_maxFile > 0) {
      
        }
}


