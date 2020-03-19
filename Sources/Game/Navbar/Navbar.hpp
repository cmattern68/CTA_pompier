#ifndef NAVBAR_HPP_
#define NAVBAR_HPP_

#include "MissionBoard.hpp"
#include "Texture.hpp"
#include "SpriteButton.hpp"

namespace cta::game {
    class Navbar {
        public:
            ~Navbar() = default;
            Navbar();
            Navbar(const Navbar &) = delete;
            Navbar &operator=(const Navbar &) = delete;
            void draw(std::shared_ptr<cta::engine::Window> &window);

            void updateMission(const std::size_t &);

            bool onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &);
        private:
            std::unique_ptr<cta::engine::shape::RectangleShape> _background;
            std::unique_ptr<cta::engine::Texture> _icon;
            std::unique_ptr<cta::engine::IButton> _settingsBtn;
            std::unique_ptr<cta::game::navbar::MissionBoard> _board;
    };
}

#endif