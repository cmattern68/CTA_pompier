#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include "Modal.hpp"

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
            void draw(std::shared_ptr<cta::engine::Window> &);
        private:
            bool _isOpen;
            std::unique_ptr<cta::engine::Modal> _modal;
    };
}

#endif