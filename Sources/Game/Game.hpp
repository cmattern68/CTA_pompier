#ifndef GAME_HPP_
#define GAME_HPP_

#include "Window.hpp"
#include "Navbar.hpp"
#include "SceneryManager.hpp"

namespace cta::game {
    class Game {
        public:
            ~Game() = default;
            Game(std::shared_ptr<cta::engine::Window> &);
            Game(const Game &) = delete;
            Game &operator=(const Game &) = delete;
            void run(std::size_t);
            void draw();
            void switchScene(EScene);
        private:
            std::shared_ptr<cta::engine::Window> _window;
            std::unique_ptr<Navbar> _navbar;
            std::unique_ptr<SceneryManager> _manager;            
    };
}

#endif