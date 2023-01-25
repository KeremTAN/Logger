#include "JsonParser.hpp"
#include <unistd.h>

#define passCondition   m_sourceText[i]=='{' || m_sourceText[i]=='\"' || m_sourceText[i]==9 || m_sourceText[i]==32 || m_sourceText[i]==':' || m_sourceText[i]==','
#define validConditon m_sourceText[i]!='\"' && m_sourceText[i]!='}' && m_sourceText[i] !=',' && m_sourceText[i] !=EOF

JsonParser::JsonParser(const std::string& jsonFileName){
    m_curr= CurrentPath::getInstance();
    std::ifstream configFile(m_curr->getPath()+jsonFileName, std::ios::in);
    std::string tmp;
    while (getline(configFile, tmp)) {
        m_sourceText+=tmp;
    }
    configFile.close();
    parse();
}
JsonParser::~JsonParser(){
    m_sourceText.clear();
    m_JsonObjects.clear();
}

int JsonParser::getMaxLogFiles(){
    if(m_JsonObjects.size()!=0)
        return std::stoi(m_JsonObjects["maxLogFiles"]);
    return 1;
}

LogFrequency JsonParser::getLogFrequency(){
    if(m_JsonObjects.size()!=0)
        return Frequency::convert(m_JsonObjects["logFrequency"]);
    return LogFrequency::Daily;
}

LogLevel JsonParser::getLogLevel(){
    if(m_JsonObjects.size()!=0)
        return Level::convert(m_JsonObjects["logLevel"]);
    return LogLevel::Undefined;
}

void JsonParser::parse(){
    std::string keyToken="", valueToken="";
    if(m_JsonObjects.size()!=0)
        m_JsonObjects.clear();
   
    bool isKey = 1;
    for(int i=0; i<m_sourceText.size(); i++){
        if(passCondition){
            continue;
        }
        if(isKey){
            while(validConditon){
                keyToken+=m_sourceText[i++];
            }
            isKey = 0; 
        }
        else{
            while(validConditon){
                valueToken+= std::tolower(m_sourceText[i++]);
            }
            m_JsonObjects.insert({keyToken, valueToken});
            keyToken="";
            valueToken="";
            isKey = 1;
        }       
    }
}

std::unordered_map<std::string, std::string>& JsonParser::items(){
    return m_JsonObjects;
}