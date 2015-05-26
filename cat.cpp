#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char *argv[])
{
    std::vector<std::istream*> inputs;
    if (argc >= 2) {
        for (int i = 1; i < argc; i++) {
            std::istream *f = new std::ifstream(argv[i], std::ifstream::in | std::ifstream::binary);
            if (!*f) {
                std::cerr << argv[i] << ": No such file or directory" << std::endl;
                return 1;
            }
            inputs.push_back(f);
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
    
    // FIXME Do we have to close() the streams or are they 
    //       automatically closed on program ending?

    return 0;
}

