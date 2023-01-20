
#pragma once
#ifndef CURRENTPATH_HPP
#define CURRENTPATH_HPP
#include<iostream>
#include<string>
#include <unistd.h>

std::string path;
namespace CurrentPath{
    std::string& getPath(){
        char buffer[PATH_MAX];
        if (getcwd(buffer, sizeof(buffer)) == NULL) {
            perror("getcwd() error");
        }
        path=buffer;
        return path;
    }
}
#endif
