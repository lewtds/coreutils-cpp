#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::istream*> inputs;
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            inputs.push_back(new std::ifstream(argv[i], std::ifstream::in | std::ifstream::binary));
        }
    } else {
        inputs.push_back(&std::cin);
    }

    char buf[512];
    for(auto input : inputs) {
        while (*input) {
            input->read(buf, sizeof(buf));
    
            // Are we at end of file?
            if (*input) {
                std::cout.write(buf, sizeof(buf));
            } else {
                std::cout.write(buf, input->gcount());
            }
        }
    }

    return 0;
}

