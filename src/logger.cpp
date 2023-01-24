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
                perror ("File could not open !");
                return EXIT_FAILURE;
        }
 
    return file_count;
}

void Logger::sleepLog(){
       switch (m_frequency) {
        case LogFrequency::Second:
                sleep(std::chrono::seconds(1));
        break;

        case LogFrequency::Minute:
                sleep(std::chrono::minutes(1));
        break;

        case LogFrequency::Hourly:
                sleep(std::chrono::hours(1));
        break;

        default:
                sleep(std::chrono::hours(24));
        break;
       }
}

void Logger::log(const char* logType, const char* message){

        std::string filePath= "logs/"+getUTCDate()+".log"; 
        m_logFile.open(filePath, std::ios::app); 

        m_logFile << "[" << getUTCDate() << "] " << message << std::endl;


        m_logFile.close();

        if (m_maxFile < getCountOfLogs()) {
                
        }
}


