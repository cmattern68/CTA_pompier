#include "Event.hpp"

namespace cta::engine {
    Event::Event() {
    }

    std::pair<std::size_t, std::size_t> Event::getMousePosition() {
        sf::Vector2i pos = sf::Mouse::getPosition();
        return std::make_pair(pos.x, pos.y);
    }

    bool Event::mouseEvent(EEvent evt) {
        return sf::Mouse::isButtonPressed((sf::Mouse::Button)evt);
    }
}