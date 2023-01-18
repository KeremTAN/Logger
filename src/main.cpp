#include <iostream>
#include "logger.hpp"
#include "json.h"
#include "json-forwards.h"
#include "json/json.h"
#include "json/json_features.h"
#include "json/allocator.h"
#include "json/assertions.h"
#include "json/config.h"
#include "json/forwards.h"
#include "json/reader.h"
#include "json/value.h"
#include "json/version.h"
#include "json/writer.h"


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