#include <iostream>
#include "logger.hpp"
#include "json.h"


int main(int argc, char** argv){

    std::ifstream configFile("config.json");
    Json::Value config;
    configFile >> config;
    
    std::string logFileName = config["logFileName"].asString();
    int maxFile             = config["maxLogFiles"].asInt();
    int frequency           = config["logFrequency"].asInt();
    std::string level       = config["logLevel"].asString();

    std::cout<<logFileName<<" "<<maxFile<<" "<<frequency<<" "<<level;

    std::cin.get();
}