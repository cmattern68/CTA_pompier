#include "SpriteButton.hpp"
#include <iostream>

namespace cta::engine::button {
    SpriteButton::SpriteButton(
        std::pair<std::size_t, std::size_t> pos,
        std::string path,
        Rect rect,
        std::pair<float, float> scale,
        bool isClickable
    ) {
        _isClickable = isClickable;
        _pos = pos;        
        _texture = std::make_unique<Texture>(
            path,
            std::make_pair(_pos.first, _pos.second),
            rect,
            scale
        );
    }

    void SpriteButton::setPos(std::pair<std::size_t, std::size_t> pos) {
        _pos = pos;
        _texture->setPos({_pos.first, _pos.first});
    }

    bool SpriteButton::isHovered(std::pair<std::size_t, std::size_t> mousePos) {
                        
        if (mousePos.first >= _pos.first && mousePos.first <= _pos.first + _texture->getRect().rectWidth) {                        
            if (mousePos.second >= _pos.second && mousePos.second <= _pos.second + _texture->getRect().rectHeight) {                
                return true;
            }
        }                        
        return false;
    }

    bool SpriteButton::isClicked(std::shared_ptr<cta::engine::Window> &window) {
        if (cta::engine::Event::mouseEvent(cta::engine::EEvent::LeftClick))
            if (isHovered(cta::engine::Event::getMousePosition(window->getPosition())))
                return true;
        return false;
    }

    void SpriteButton::draw(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_texture->getSprite());
    }
}