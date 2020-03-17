#include "Settings.hpp"

namespace cta::shared
{
    Settings::Settings() {
        _modal = nullptr;
        _isOpen = false;
    }

    void Settings::open() {        
        _modal = std::make_unique<cta::engine::Modal>(
            std::make_pair(640, 790),
            std::make_pair(640, 80),
            "Parametres",
            std::make_tuple(255, 255, 255),
            std::make_tuple(0, 0, 0),
            1
        );
        _isOpen = true;
    }

    bool Settings::close(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {
        if (_modal->closeEvent(window, evt)) {
            _modal = nullptr;
            _isOpen = false;
            return true;
        }        
        return false;
    }

    void Settings::draw(std::shared_ptr<cta::engine::Window> &window) {
        _modal->draw(window);
    }
}
