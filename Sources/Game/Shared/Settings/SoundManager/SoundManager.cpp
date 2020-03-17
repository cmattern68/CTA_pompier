#include "SoundManager.hpp"

namespace cta::shared::settings
{
    SoundManager::SoundManager(std::pair<std::size_t, std::size_t> pos, std::size_t soundValue) {        
        _text = std::make_unique<cta::engine::Text>(
            std::make_pair(pos.first + 10, pos.second),
            std::make_tuple(0, 0, 0),
            22,
            "Volume:",
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::BOLD
        );        
        _line = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(pos.first + 150, pos.second + 14),
            std::make_pair(300, 2),
            std::make_tuple(0, 0, 0)
        );
        _cursorPos = std::make_pair((soundValue * 3) + 780, pos.second + 4);        
        _cursor = std::make_unique<cta::engine::shape::RectangleShape>(
            _cursorPos,
            std::make_pair(10, 22),
            std::make_tuple(0, 0, 0)
        );
        _soundValue = soundValue;
        _value = std::make_unique<cta::engine::Text>(
            std::make_pair(pos.first + 500, pos.second),
            std::make_tuple(0, 0, 0),
            22,
            std::to_string(_soundValue) + " %",
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::BOLD
        );
        _hold = false;        
    }

    void SoundManager::update(std::shared_ptr<cta::engine::Window> &window, const std::shared_ptr<cta::engine::Event> &evt) {        
        std::pair<std::size_t, std::size_t> mousePos = cta::engine::Event::getMousePosition(window->getPosition());
        bool pressedValue = false;
        if (evt != nullptr) {
            pressedValue = evt->isMousePressedEvent(cta::engine::LeftClick);
            if (evt->isMouseReleasedEvent(cta::engine::LeftClick)) {
                _hold = false;                                
            }                
        }        
        if (pressedValue || _hold) {
            if (mousePos.first >= (std::size_t)_cursorPos.first && mousePos.first <= (std::size_t)_cursorPos.first + 10) {
                if (mousePos.second >= _cursorPos.second && mousePos.second <= _cursorPos.second + 22) {
                    _hold = true;
                }
            }
        }
        if (_hold) {
            if (mousePos.first >= 790 && mousePos.first <= 1080) {                
                _cursor->setPos(std::make_pair(mousePos.first, 174));
                _cursorPos = std::make_pair(mousePos.first, 174);
            } else if (mousePos.first < 790) {
                _cursor->setPos(std::make_pair(790, 174));
                _cursorPos = std::make_pair(790, 174);
            } else if (mousePos.first > 1080) {
                _cursor->setPos(std::make_pair(1080, 174));
                _cursorPos = std::make_pair(1080, 174);
            }                    
        }
        if (((_cursorPos.first - 780) / 3) < 0 || _cursorPos.first == 790)
            _soundValue = 0;
        else
            _soundValue = (_cursorPos.first - 780) / 3;
        _value->setText(std::to_string(_soundValue) + " %");
    }

    void SoundManager::draw(std::shared_ptr<cta::engine::Window> &window) {
        update(window, nullptr);
        window->draw(_text->getText());
        window->draw(_line->getShape());
        window->draw(_cursor->getShape());
        window->draw(_value->getText());        
    }
}
