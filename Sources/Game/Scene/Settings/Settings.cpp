#include "Settings.hpp"

namespace cta::game::scene
{
    Settings::Settings() {
        std::cout << "New Settings" << std::endl;   
    }

    void Settings::performScene() {

    }

    void Settings::drawScene(std::shared_ptr<cta::engine::Window> &window) {
        (void)window;
    }
}
