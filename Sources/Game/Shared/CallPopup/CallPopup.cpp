#include "CallPopup.hpp"
#include <time.h>
#include <stdlib.h>

namespace cta::shared {
    CallPopup::CallPopup(std::shared_ptr<cta::engine::Window> &window, std::size_t sound) {        
        std::pair<std::size_t, std::size_t> windowSize = window->getSize();
        std::string entrance("Appel 18 Entrant");
        std::string nb("+33600000000");
        int s1 = 0;
        srand(time(NULL));
        _background = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(windowSize.first - 212, windowSize.second - 262),
            std::make_pair(200, 250),
            std::make_tuple(61, 61, 61)
        );
        if ((rand() % 10) >= 8) {
            entrance = "Appel 112 Entrant";
            s1 = -6;
        }
        if ((rand() % 10) >= 8)
            nb = "+33" + std::to_string((rand() % (596000000 - 130000000 + 1)) + 130000000);
        else
            nb = "+33" + std::to_string((rand() % (700000000 - 600000000 + 1)) + 600000000);
        _text.push_back(std::make_unique<cta::engine::Text>(
            std::make_pair(windowSize.first - 197 + s1, windowSize.second - 250),
            std::make_tuple(255, 255, 255),
            20,
            entrance,
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::BOLD
        ));
        _text.push_back(std::make_unique<cta::engine::Text>(
            std::make_pair(windowSize.first - 173, windowSize.second - 222),
            std::make_tuple(255, 255, 255),
            18,
            nb,
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::REGULAR
        ));
        _avatar = std::make_unique<cta::engine::Texture>(
            "Resources/Call/avatar.png",
            std::make_pair(windowSize.first - 160, windowSize.second - 198),
            cta::engine::Rect {0, 0, 100, 100},
            std::make_pair(1, 1)
        );
                
        _aButton = std::make_unique<cta::engine::button::SpriteButton>(
                std::make_pair((windowSize.first - 180), (windowSize.second - 80)),
                "Resources/Call/answer.png",
                cta::engine::Rect {0, 0, 40, 40},
                std::make_pair(1, 1),
                true
            );
        _dButton = std::make_unique<cta::engine::button::SpriteButton>(
                std::make_pair((windowSize.first - 85), (windowSize.second - 80)),
                "Resources/Call/decline.png",
                cta::engine::Rect {0, 0, 40, 40},
                std::make_pair(1, 1),
                true
            );
        _sound = std::make_unique<cta::engine::Sound>("Resources/Sound/ring.ogg", sound);
    }

    std::string CallPopup::onEvent(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {        
        if (_aButton->isClicked(window, evt))
            return "answer";
        if (_dButton->isClicked(window, evt))
            return "decline";        
        return "none";
    }

    void CallPopup::draw(std::shared_ptr<cta::engine::Window> &window) {             
        window->draw(_background->getShape());
        for (auto &txt : _text) {
            window->draw(txt->getText());
            window->draw(_avatar->getSprite());
        }
        _aButton->draw(window);
        _dButton->draw(window);        
    }
}