
#pragma once
#ifndef CURRENTPATH_HPP
#define CURRENTPATH_HPP
#include<iostream>
#include<string>
#include <unistd.h>


class CurrentPath{
public:
    static CurrentPath* getInstance();
    std::string& getPath();
private:
    CurrentPath();
    static CurrentPath* m_Instance;
    std::string path;
};
#endif
