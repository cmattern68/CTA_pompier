#include "SpriteButton.hpp"
#include <iostream>

namespace cta::engine::button {
    SpriteButton::SpriteButton(
        std::pair<Pos, Pos> pos,
        std::string path,
        Rect rect,
        std::pair<float, float> scale,
        bool isClickable
    ) {
        _isClickable = isClickable;
        _pos = pos;        
        _texture = std::make_unique<Texture>(
            path,
            std::make_pair(_pos.first.x, _pos.first.y),
            rect,
            scale
        );
    }

    void SpriteButton::setPos(std::pair<Pos, Pos> pos) {
        _pos = pos;
        _texture->setPos({_pos.first.x, _pos.first.y});
    }

    bool SpriteButton::isHovered(std::pair<std::size_t, std::size_t> mousePos) {
                
        //std::cout << "X: " << mousePos.first << " >= " << _pos.first.x << " && " << mousePos.first << " <= " << _pos.second.x << std::endl;
        if (mousePos.first >= _pos.first.x && mousePos.first <= _pos.second.x) {
            //std::cout << "Y: " << mousePos.second << " >= " << _pos.first.y << " && " << mousePos.second << " <= " << _pos.second.y << std::endl;
            if (mousePos.second >= _pos.first.y && mousePos.second <= _pos.second.y) {
                std::cout << "true" << std::endl;
                return true;
            }
        }                        
        return false;
    }

    bool SpriteButton::isClicked() {        
        if (isHovered(cta::engine::Event::getMousePosition()) && cta::engine::Event::mouseEvent(cta::engine::EEvent::LeftClick))
            return true;
        return false;
    }

    void SpriteButton::draw(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_texture->getSprite());
    }
}