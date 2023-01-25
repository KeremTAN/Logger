#ifndef LogFrequency_HPP
#define LogFrequency_HPP
enum  LogFrequency
{
    Daily, Hourly, Minute, Second
};
namespace Frequency{
    static LogFrequency convert(const std::string& stringFrequency){
        LogFrequency frequency;
        if(stringFrequency=="second")
            frequency=LogFrequency::Second;

        else if (stringFrequency=="minute")
            frequency=LogFrequency::Minute;

        else if (stringFrequency=="hourly")
            frequency=LogFrequency::Hourly;

        else
            frequency=LogFrequency::Daily;
        return frequency;
    }
};
#endif