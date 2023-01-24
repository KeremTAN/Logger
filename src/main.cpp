#include <iostream>
#include <fstream>

#include "Logger.hpp"
#include "JsonParser.hpp"
#include "nlohmann/json.hpp"
#include "json.hpp"


using json = nlohmann::json;

int main(int argc, char** argv){
  JsonParser json("/configs/config.json");
  json.parse();

  int maxLogFiles = json.getMaxLogFiles();
  LogFrequency logFrequency = json.getLogFrequency();
  LogLevel logLevel = json.getLogLevel();

  Logger logger(maxLogFiles, logFrequency, logLevel, true); 
  logger.log("This is a log about logger");

  std::cin.get();
}