#include "CurrentPath.hpp"

CurrentPath* CurrentPath::m_Instance=0;
CurrentPath::CurrentPath(){}

 CurrentPath::~CurrentPath(){
    delete m_Instance;
 }

CurrentPath* CurrentPath::getInstance(){
    if(m_Instance)
        return m_Instance;
    m_Instance= new CurrentPath();
    return m_Instance;
}

std::string& CurrentPath::getPath(){
    char buffer[PATH_MAX];
    if (getcwd(buffer, sizeof(buffer)) == NULL) {
        perror("getcwd() error");
    }
    path=buffer;
    return path;
}