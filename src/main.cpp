#include <iostream>
#include <fstream>

#include "logger.hpp"
#include "json.hpp"
#include "JsonParser.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;
int main(int argc, char** argv){

std::ifstream f("/path/config.json");
json data = json::parse(f);

for (auto& it : data.items()) 
  std::cout << it.key() << " : " << it.value() << "\n";
/*
    JsonParser json("/config.json");
    json.parse();
*/

    std::cin.get();
}