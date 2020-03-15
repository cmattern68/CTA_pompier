#include "Settings.hpp"

namespace cta::shared
{
    Settings::Settings() {
        _volume = 100;
        _background = nullptr;
    }

    void Settings::setup() {
        _background = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(640, 80),
            std::make_pair(640, 790),
            std::make_tuple(255, 255, 255)
        );
        _background->setBorder(
            1,
            std::make_tuple(0, 0, 0)
        );
        _closeBtn = std::make_unique<cta::engine::button::SpriteButton>(
            std::make_pair((1238), (84)),
            "Resources/Settings/close.png",
            cta::engine::Rect {0, 0, 32, 32},
            std::make_pair(1, 1),
            true
        );
        _rectangleShape.push_back(std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(640, 120),
            std::make_pair(640, 1),
            std::make_tuple(0, 0, 0)
        ));
        _text.push_back(std::make_unique<cta::engine::Text>(
            std::make_pair(644, 84),
            std::make_tuple(0, 0, 0),
            24,
            "Parametres",
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::BOLD
        ));
    }

    void Settings::show() {        
    }

    bool Settings::onEvent(std::shared_ptr<cta::engine::Window> &window) {
        if (_closeBtn->isClicked(window))
            return false;
        return true;
    }

    void Settings::draw(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_background->getShape());
        _closeBtn->draw(window);
        for (auto &shape : _rectangleShape)
            window->draw(shape->getShape());
        for (auto &text : _text)
            window->draw(text->getText());
    }
}
