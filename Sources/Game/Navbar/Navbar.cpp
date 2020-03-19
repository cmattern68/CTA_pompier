#include "Navbar.hpp"

namespace cta::game
{
    Navbar::Navbar() {
        _background = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(0, 0),
            std::make_pair(1920, 60),
            std::make_tuple(117, 21, 30)
        );
        _icon = std::make_unique<cta::engine::Texture>(
            "Resources/Icon/icon.png",
            std::make_pair(10, 4),
            cta::engine::Rect {0, 0, 184, 304},
            std::make_pair(0.17, 0.17)
        );
        _settingsBtn = std::make_unique<cta::engine::button::SpriteButton>(
                std::make_pair((1920 - 52), (4)),
                "Resources/Settings/settings.png",
                cta::engine::Rect {0, 0, 48, 48},
                std::make_pair(1, 1),
                true
        );
        _board = std::make_unique<cta::game::navbar::MissionBoard>();
    }

    void Navbar::updateMission(const std::size_t &nb) {
        _board->setMissionNb(nb);
    }

    bool Navbar::onEvent(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {        
        if (_settingsBtn->isClicked(window, evt))
            return true;
        return false;
    }

    void Navbar::draw(std::shared_ptr<cta::engine::Window> &window) {
        _board->draw(window);
        window->draw(_background->getShape());
        window->draw(_icon->getSprite());
        _settingsBtn->draw(window);        
    }
}
