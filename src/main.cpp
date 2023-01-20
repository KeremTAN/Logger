#include <iostream>
#include <fstream>

#include "logger.hpp"
#include "json.hpp"
#include "JsonParser.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
int main(int argc, char** argv){
//std::ifstream f("/path/config.json");
//json data = json::parse(f);
JsonParser json("/config.json");
json.parse();

for (auto& it : json.items()) 
  std::cout << it.first << " : " << it.second << "\n";


    std::cin.get();
}