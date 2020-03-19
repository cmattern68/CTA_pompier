#include "Settings.hpp"

namespace cta::shared
{
    Settings::Settings() {
        _modal = nullptr;
        _leave = nullptr;
        _isOpen = false;
        _sound = 100;        
    }

    void Settings::open() {        
        _modal = std::make_unique<cta::engine::Modal>(
            std::make_pair(640, 790),
            std::make_pair(640, 80),
            "Parametres",
            std::make_tuple(221, 224, 231),
            std::make_tuple(0, 0, 0),
            1
        );
        _leave = std::make_unique<cta::engine::button::RoundedRectangleShapeButton>(
            std::make_pair(1150, 800),
            std::make_pair(110 ,50),
            std::make_tuple(188, 21, 28),
            "Quitter",
            true
        );
        _minPos = std::make_pair(640, 170);         
        _soundManager = std::make_unique<cta::shared::settings::SoundManager>(_minPos, _sound);
        _isOpen = true;        
    }

    bool Settings::close(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {
        if (_modal->closeEvent(window, evt)) {
            _modal = nullptr;
            _soundManager = nullptr;
            _leave = nullptr;
            _isOpen = false;
            return true;
        }        
        return false;
    }

    void Settings::onEvent(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {
        _soundManager->update(window, evt);
        _sound = _soundManager->getSound();
        if (_leave->isClicked(window, evt))
            window->close();
    }

    void Settings::draw(std::shared_ptr<cta::engine::Window> &window) {
        _modal->draw(window);
        _leave->draw(window);
        _soundManager->draw(window);        
    }
}
