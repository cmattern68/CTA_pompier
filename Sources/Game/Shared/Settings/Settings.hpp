#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include "RectangleShape.hpp"
#include "Window.hpp"
#include "SpriteButton.hpp"
#include "Text.hpp"

namespace cta::shared {
    class Settings {
        public:
            ~Settings() = default;
            Settings();
            Settings(const Settings &) = delete;
            Settings &operator=(const Settings &) = delete;

            void setVolume(const unsigned short int &volume) { _volume = volume; };
            unsigned short int getVolume() { return _volume; };

            void setup();
            void show();
            bool onEvent(std::shared_ptr<cta::engine::Window> &window);
            void draw(std::shared_ptr<cta::engine::Window> &);

        private:            
            unsigned short int _volume;
            std::unique_ptr<cta::engine::shape::RectangleShape> _background;
            std::vector<std::unique_ptr<cta::engine::shape::RectangleShape>> _rectangleShape;
            std::unique_ptr<cta::engine::IButton> _closeBtn;
            std::vector<std::unique_ptr<cta::engine::Text>> _text;
    };
}

#endif