#ifndef NAVBAR_HPP_
#define NAVBAR_HPP_

#include <memory>
#include "RectangleShape.hpp"
#include "Texture.hpp"
#include "Window.hpp"

namespace cta::game {
    class Navbar {
        public:
            ~Navbar() = default;
            Navbar();
            Navbar(const Navbar &) = delete;
            Navbar &operator=(const Navbar &) = delete;
            void draw(std::shared_ptr<cta::engine::Window> &window);
        private:
            std::unique_ptr<cta::engine::shape::RectangleShape> _background;
            std::unique_ptr<cta::engine::Texture> _icon;
    };
}

#endif