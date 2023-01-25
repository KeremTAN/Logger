#ifndef LOGLEVEL_HPP
#define LOGLEVEL_HPP
enum class LogLevel
{
    Warn, Error, Info, Debug, Undefined
};

namespace Level{
    static LogLevel convert(const std::string& stringLevel){
        LogLevel level;

        if (stringLevel=="warn")   
            level=LogLevel::Warn;

        else if(stringLevel=="error")
            level=LogLevel::Error;

        else if (stringLevel=="info")
            level=LogLevel::Info;

        else if(stringLevel=="debug")
            level=LogLevel::Debug;
        else
            level=LogLevel::Undefined;

        return level;
    }
    static std::string convert(const LogLevel& logLevel){
        std::string level;
        switch (logLevel)
        {
        case LogLevel::Warn:
            level="Warn";
        break;

        case LogLevel::Error:
            level="Error";
        break;

        case LogLevel::Debug:
            level="Debug";
        break;

        case LogLevel::Info:
            level="Info";
        break;

        default:
            level="Undefined";
        break;
        }
        return level;
    }
};
#endif