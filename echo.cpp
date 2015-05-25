#include <iostream>
#include <cstdlib>
#include <unistd.h>


void show_help() {
    std::cout << "Haha this is help" << std::endl;
}

int main(int argc, char *argv[])
{
    bool new_line_at_end = true;
    bool separate_arguments = true;
    bool interpret_backslash = false;

    int opt;
    while ((opt = getopt(argc, argv, "nhes")) != -1) {
        switch (opt) {
        case 'h':
            show_help();
            return 0;
            break;
        case 'n':
            new_line_at_end = false;
            break;
        case 's':
            separate_arguments = false;
            break;
        case 'e':
            interpret_backslash = true;
            break;
        default:
            show_help();
            exit(EXIT_FAILURE);
        }
    }

    // Start after the last option argument
    for (int i = optind; i < argc; i++) {
        if (!interpret_backslash) {
            std::cout << argv[i];
        } else {
            char *c = argv[i];
            bool escape = false;
            char combined = 0;

            while (*c) {
                if (escape) {
                    switch (*c) {
                    case '\\':
                        combined = '\\';
                        break;
                    case 'a':
                        combined = '\a';
                        break;
                    case 'b':
                        combined = '\b';
                        break;
                    case 'c':
                        return 0;
                    default:
                        combined = *c;
                    }
                    
                    std::cout << combined;
                    escape = false;
                } else if (*c == '\\') {
                    escape = true;
                } else {
                    std::cout << *c;
                }

                c++;
            }
        }

        if (separate_arguments && i != argc - 1) {
            std::cout << " ";
        }
    }
    
    if (new_line_at_end) {
        std::cout << std::endl;
    }
    
    return 0;
}
