#include "Main.hpp"

int main(int ac, char **av, char **env) {
    if (!env)
        return 84;
    (void)ac;
    (void)av;
    std::cout << "Hello World!" << std::endl;
    return 0;
}