#include <iostream>
#include <fstream>

#include "Logger.hpp"
#include "json.hpp"
#include "JsonParser.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

int main(int argc, char** argv){
  //std::ifstream f("/path/config.json");
  //json data = json::parse(f);
  JsonParser json("/config.json");
  json.parse();

  std::string logFileName = json.items()["logFileName"];
  int maxLogFiles = stoi(json.items()["maxLogFiles"]);
  int logFrequency = stoi(json.items()["logFrequency"]);
  std::string logLevel = json.items()["logLevel"];
  
  Logger logger(logFileName, maxLogFiles, logFrequency); 
  logger.log("hiii");

  std::cin.get();
}