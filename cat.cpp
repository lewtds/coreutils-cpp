#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    std::istream *input;
    if (argc == 2) {
        input = new std::ifstream(argv[1], std::ifstream::in | std::ifstream::binary);
    } else {
        input = &std::cin;
    }
    
    
    char buf[512];
    while (*input) {
        
        input->read(buf, sizeof(buf));

        // Check the status of the last read
        if (*input) {
            
            std::cout.write(buf, sizeof(buf));
        } else {
            std::cout.write(buf, input->gcount());
        }
    }

    return 0;
}

