#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include "Modal.hpp"
#include "SoundManager.hpp"
#include "RoundedRectangleShapeButton.hpp"

namespace cta::shared {
    class Settings {
        public:
            ~Settings() = default;
            Settings();
            Settings(const Settings &) = delete;
            Settings &operator=(const Settings &) = delete;
            
            void open();
            bool isOpen() { return _isOpen; };
            bool close(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &);
            void onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &);
            void draw(std::shared_ptr<cta::engine::Window> &);

            std::size_t getSound() { return _sound; };
        private:
            bool _isOpen;
            std::unique_ptr<cta::engine::Modal> _modal;
            std::unique_ptr<cta::shared::settings::SoundManager> _soundManager;
            std::unique_ptr<cta::engine::IButton> _leave;
            std::pair<std::size_t, std::size_t> _minPos;

            std::size_t _sound;            
    };
}

#endif