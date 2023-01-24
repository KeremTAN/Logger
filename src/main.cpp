#include <iostream>
#include <fstream>

#include "Logger.hpp"
#include "json.hpp"
#include "JsonParser.hpp"
#include "nlohmann/json.hpp"


using json = nlohmann::json;

int main(int argc, char** argv){
  JsonParser json("/configs/config.json");
  json.parse();

  int maxLogFiles = json.getMaxLogFiles();
  LogFrequency logFrequency = json.getLogFrequency();
  LogLevel logLevel = json.getLogLevel();
 
  
  Logger logger(maxLogFiles, logFrequency, logLevel, 1); 

  logger.log("This is a log about logger");


  std::cin.get();
}