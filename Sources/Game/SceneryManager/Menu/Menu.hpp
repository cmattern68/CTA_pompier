#ifndef MENU_HPP_
#define MENU_HPP_

#include "RectangleShape.hpp"
#include "RectangleShapeButton.hpp"
#include "Window.hpp"
#include "IScene.hpp"

namespace cta::game::scenerymanager {
    class Menu {
        public:
            ~Menu() = default;
            Menu();
            Menu(const Menu &) = delete;
            Menu &operator=(const Menu &) = delete;                    

            cta::game::EScene onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &);

            bool insert(const cta::game::EScene &, const std::string &);
            bool remove(const cta::game::EScene &);            

            void setTime();
            void draw(std::shared_ptr<cta::engine::Window> &, const EScene &);
        private:
            std::unordered_map<cta::game::EScene, std::unique_ptr<cta::engine::IButton>> _button;
            std::string _time;
            std::unique_ptr<cta::engine::Text> _timeText;
    };
}

#endif