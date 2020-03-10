#include "Event.hpp"
#include <iostream>

namespace cta::engine {
    Event::Event() {
    }

    std::pair<std::size_t, std::size_t> Event::getMousePosition(std::pair<std::size_t, std::size_t> windowPos) {        
        sf::Vector2i pos = sf::Mouse::getPosition();        
        return std::make_pair(pos.x - windowPos.first, pos.y - 57);
    }

    bool Event::mouseEvent(EEvent evt) {        
        return sf::Mouse::isButtonPressed((sf::Mouse::Button)evt);
    }
}