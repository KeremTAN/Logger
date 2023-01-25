#include <iostream>
#include <fstream>
#include "Logger.hpp"
#include "JsonParser.hpp"

// nlohmann's json lib
#include "nlohmann/json.hpp"
#include "json.hpp"

using json = nlohmann::json;

int main(int argc, char** argv){
  JsonParser json("/configs/config.json");

  int maxLogFiles = json.getMaxLogFiles();
  LogFrequency logFrequency = json.getLogFrequency();
  LogLevel logLevel = json.getLogLevel();

  Logger logger(maxLogFiles, logFrequency, logLevel, true); 
  logger.log("This is a log about logger");

  std::cin.get();
}