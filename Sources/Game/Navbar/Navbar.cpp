#include "Navbar.hpp"

namespace cta::game
{
    Navbar::Navbar() {
        _background = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(0, 0),
            std::make_pair(1920, 60),
            std::make_tuple(188, 21, 28)
        );
        _icon = std::make_unique<cta::engine::Texture>(
            "Resources/Icon/icon.png",
            std::make_pair(10, 4),
            cta::engine::Rect {0, 0, 184, 304},
            std::make_pair(0.17, 0.17)
        );
    }

    void Navbar::draw(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_background->getShape());
        window->draw(_icon->getSprite());
    }
}
