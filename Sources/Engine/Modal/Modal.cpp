#include "Modal.hpp"

namespace cta::engine
{
    Modal::Modal(
        std::pair<std::size_t, std::size_t> size,
        std::pair<std::size_t, std::size_t> pos,
        std::string name,
        std::tuple<unsigned short int, unsigned short int, unsigned short int> bgColor,
        std::tuple<unsigned short int, unsigned short int, unsigned short int> borderColor,
        std::size_t borderSize
    ) {        
        _bg = std::make_unique<cta::engine::shape::RoundedRectangleShape>(pos, size, bgColor, 10.0);
        _bg->setBorder(borderSize, borderColor);
        _name = std::make_unique<cta::engine::Text>(
            std::make_pair(pos.first + 20, pos.second + 4),
            std::make_tuple(0, 0, 0),
            24,
            name,
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::BOLD
        );
        _closeBtn = std::make_unique<cta::engine::button::SpriteButton>(
            std::make_pair(pos.first + size.first - 50, (84)),
            "Resources/Settings/close.png",
            cta::engine::Rect {0, 0, 32, 32},
            std::make_pair(1, 1),
            true
        );
        _hr = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(pos.first, (pos.second + 40)),
            std::make_pair(size.first, 1),
            std::make_tuple(0, 0, 0)            
        );
    }

    bool Modal::closeEvent(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {        
        return _closeBtn->isClicked(window, evt);        
    }

    void Modal::draw(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_bg->getShape());
        window->draw(_name->getText());
        _closeBtn->draw(window);
        window->draw(_hr->getShape());
    }
}
