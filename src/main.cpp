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

  std::cout<<"Red Text";
  std::string logFileName = json.items()["logFileName"];
  int maxLogFiles = stoi(json.items()["maxLogFiles"]);
  int logFrequency = stoi(json.items()["logFrequency"]);
  std::string logLevel = json.items()["logLevel"];
  
  Logger logger(logFileName, maxLogFiles, logFrequency); 
  logger.log("hiii");

  std::cin.get();
}