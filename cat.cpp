#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
    char buf[512];
    while (!std::cin.eof()) {
        std::cin.read(buf, sizeof(buf));
        std::cout << buf;
    }

    return 0;
}

