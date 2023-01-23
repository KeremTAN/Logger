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

  int maxLogFiles = stoi(json.items()["maxLogFiles"]);
  LogFrequency logFrequency = json.getLogFrequency();
  std::string logLevel = json.items()["logLevel"];
 
  
  Logger logger(maxLogFiles, logFrequency, 1); 
  while(true){
    logger.Warn("This is a Warn");
  }
/*
  logger.Error("This is an Error");
  logger.Info("This is an Info");
  logger.Debug("This is an Debug");
  */

  std::cin.get();
}