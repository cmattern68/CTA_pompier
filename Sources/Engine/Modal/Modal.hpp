#ifndef MODAL_HPP_
#define MODAL_HPP_

#include "RoundedRectangleShape.hpp"
#include "RectangleShape.hpp"
#include "Window.hpp"
#include "SpriteButton.hpp"
#include "Text.hpp"

namespace cta::engine {
    class Modal {
        public:
            ~Modal() = default;
            Modal(
                std::pair<std::size_t, std::size_t>,
                std::pair<std::size_t, std::size_t>,
                std::string,
                std::tuple<unsigned short int, unsigned short int, unsigned short int>,
                std::tuple<unsigned short int, unsigned short int, unsigned short int>,
                std::size_t
            );
            Modal(const Modal &) = delete;
            Modal &operator=(const Modal &) = delete;
            
            bool closeEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &);
            void draw(std::shared_ptr<cta::engine::Window> &);
        private:
            std::unique_ptr<cta::engine::shape::RoundedRectangleShape> _bg;
            std::unique_ptr<cta::engine::Text> _name;
            std::unique_ptr<cta::engine::IButton> _closeBtn;
            std::unique_ptr<cta::engine::shape::RectangleShape> _hr;
    };
}

#endif