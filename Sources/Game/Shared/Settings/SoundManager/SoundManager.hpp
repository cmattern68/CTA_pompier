#ifndef SOUNDMANAGER_HPP_
#define SOUNDMANAGER_HPP_

#include "Text.hpp"
#include "RectangleShape.hpp"
#include "Window.hpp"
#include "Event.hpp"

namespace cta::shared::settings {
    class SoundManager {
        public:
            ~SoundManager() = default;
            SoundManager(std::pair<std::size_t, std::size_t>, std::size_t);
            SoundManager(const SoundManager &) = delete;
            SoundManager &operator=(const SoundManager &) = delete;
                        
            void update(std::shared_ptr<cta::engine::Window> &, const std::shared_ptr<cta::engine::Event> &evt);
            void draw(std::shared_ptr<cta::engine::Window> &);
            std::size_t getSound() { return _soundValue; };
        private:
            std::unique_ptr<cta::engine::Text> _text;
            std::unique_ptr<cta::engine::shape::RectangleShape> _line;
            std::unique_ptr<cta::engine::shape::RectangleShape> _cursor;
            std::unique_ptr<cta::engine::Text> _value;
            std::pair<int, std::size_t> _cursorPos;
            int _soundValue;
            bool _hold;
    };
}

#endif