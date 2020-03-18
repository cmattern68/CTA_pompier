#ifndef CALLPOPUP_HPP_
#define CALLPOPUP_HPP_

#include <vector>
#include "Window.hpp"
#include "RectangleShape.hpp"
#include "Text.hpp"
#include "Texture.hpp"
#include "SpriteButton.hpp"
#include "Sound.hpp"

namespace cta::shared {    

    class CallPopup {
        public:
            ~CallPopup() = default;
            CallPopup(std::shared_ptr<cta::engine::Window> &, std::size_t);
            CallPopup(const CallPopup &) = delete;
            CallPopup &operator=(const CallPopup &) = delete;
            void draw(std::shared_ptr<cta::engine::Window> &);
            std::string onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &);

            void pause() { _sound->pause(); };
            void play() { _sound->play(); };
        private:
            std::unique_ptr<cta::engine::shape::RectangleShape> _background;
            std::vector<std::unique_ptr<cta::engine::Text>> _text;
            std::unique_ptr<cta::engine::Texture> _avatar;
            std::unique_ptr<cta::engine::IButton> _aButton;
            std::unique_ptr<cta::engine::IButton> _dButton;
            std::unique_ptr<cta::engine::Sound> _sound;
    };
}

#endif