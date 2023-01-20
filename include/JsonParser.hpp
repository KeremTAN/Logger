/**
 * @file JsonParser.hpp
 * @author Kerem TAN
 * @brief 
 * @version 0.1
 * @date 2023-01-20
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef JSONPARSER_HPP
#define JSONPARSER_HPP
#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>


class JsonParser{
public:
    JsonParser(const std::string& jsonFileName);
    ~JsonParser();
    void parse();
    std::unordered_map<std::string, std::string>& items();

private:
    std::string                                     m_sourceText;
    std::unordered_map<std::string, std::string>    m_JsonObjects;
};
#endif