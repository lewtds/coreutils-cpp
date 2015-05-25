#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    char buf[512];
    while (!std::cin.eof()) {
        std::cin.read(buf, sizeof(buf));

        // Check the status of the last read
        if (std::cin) {
            std::cout.write(buf, sizeof(buf));
        } else {
            std::cout.write(buf, std::cin.gcount());
        }
    }

    return 0;
}

