#include <string>
#include <memory>
#include <iostream>
#include "Core.hpp"

int main(int ac, char **av, char const *const *env)
{
    (void)env;
    std::unique_ptr<cta::Core> core = nullptr;
    try {
        core = std::make_unique<cta::Core>();
        core->run(ac, av);
    } catch (std::exception const &error) {
        std::cerr << "Error :: Standard exception :: " << error.what() << std::endl;
        return 125;
    } catch (std::string const &error) {
        std::cerr << "Error :: std::string :: " << error << std::endl;
        return 125;
    } catch (char const *const error) {
        std::cerr << "Error :: C-style string :: " << error << std::endl;
        return 125;
    } catch (...) {
        std::cerr << "Error :: Unknown savage error" << std::endl;
        return 125;
    }
    return 0;
}