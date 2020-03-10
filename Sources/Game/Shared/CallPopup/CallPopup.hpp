#ifndef CALLPOPUP_HPP_
#define CALLPOPUP_HPP_

#include <vector>
#include "Window.hpp"
#include "RectangleShape.hpp"
#include "Text.hpp"
#include "Texture.hpp"
#include "SpriteButton.hpp"

namespace cta::shared {    

    class CallPopup {
        public:
            ~CallPopup() = default;
            CallPopup();
            CallPopup(const CallPopup &) = delete;
            CallPopup &operator=(const CallPopup &) = delete;
            void draw(std::shared_ptr<cta::engine::Window> &);
            void onEvent();
        private:
            std::unique_ptr<cta::engine::shape::RectangleShape> _background;
            std::vector<std::unique_ptr<cta::engine::Text>> _text;
            std::unique_ptr<cta::engine::Texture> _avatar;
            std::unique_ptr<cta::engine::IButton> _aButton;
            std::unique_ptr<cta::engine::IButton> _dButton;
    };
}

#endif