#include "JsonParser.hpp"
#include <unistd.h>

#define passCondition   m_sourceText[i]=='{' || m_sourceText[i]=='\"' || m_sourceText[i]==9 || m_sourceText[i]==32 || m_sourceText[i]==':' || m_sourceText[i]==','
#define inValidConditon m_sourceText[i]!='\"' && m_sourceText[i]!='}' && m_sourceText[i] !=',' && m_sourceText[i] !=EOF

JsonParser::JsonParser(const std::string& jsonFileName){
    m_curr= CurrentPath::getInstance();
    std::ifstream configFile(m_curr->getPath()+jsonFileName, std::ios::in);
    std::string tmp;
    while (getline(configFile, tmp)) {
        m_sourceText+=tmp;
    }
    configFile.close();
}
JsonParser::~JsonParser(){
    m_sourceText.clear();
    m_JsonObjects.clear();
}

void JsonParser::parse(){
    std::string keyToken, valueToken;
   
    bool isKey = 1;
    for(int i=0; i<m_sourceText.size(); i++){
        if(passCondition){
            continue;
        }
        if(isKey){
            while(inValidConditon){
                keyToken+=m_sourceText[i++];
            }
            isKey = 0; 
        }
        else{
            while(inValidConditon){
                valueToken+=m_sourceText[i++];
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

LogFrequency JsonParser::getLogFrequency(){
  LogFrequency frequency;
  if(m_JsonObjects.size()!=0){
    if(m_JsonObjects["logFrequency"]=="Second")
        frequency=LogFrequency::Second;

    else if (m_JsonObjects["logFrequency"]=="Minute")
        frequency=LogFrequency::Minute;

    else if (m_JsonObjects["logFrequency"]=="Hourly")
        frequency=LogFrequency::Hourly;

    else frequency=LogFrequency::Daily;
    }

    return frequency;
}
