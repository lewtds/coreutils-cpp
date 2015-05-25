#include <iostream>
#include <stdio.h>
#include "utils.hpp"

std::string call(std::string args, int* status) {
    FILE* handle = popen(args.c_str(), "r");
    
    char buffer[256];
    std::string output;
    while (fgets(buffer, 256, handle) != NULL) {
        output += buffer;
    }
    
    int s = pclose(handle);
    if (status != NULL) {
        *status = s;
    }
    return output;
}
