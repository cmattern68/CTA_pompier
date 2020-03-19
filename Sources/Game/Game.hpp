#ifndef GAME_HPP_
#define GAME_HPP_

#include "Window.hpp"
#include "Navbar.hpp"
#include "CallPopup.hpp"
#include "SceneryManager.hpp"
#include "Settings.hpp"

namespace cta::game {
    class Game {
        public:
            ~Game() = default;
            Game(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &);
            Game(const Game &) = delete;
            Game &operator=(const Game &) = delete;

            void catchEvent();
            void run();
            void draw();            
        private:
            void dispatchUserCall();
            void callAnswer();
            void updateMissionBoard();
            bool isOnCall();

            std::shared_ptr<cta::engine::Window> _window;
            std::shared_ptr<cta::engine::Event> _event;
            std::unique_ptr<Navbar> _navbar;
            std::unique_ptr<SceneryManager> _manager;
            std::unique_ptr<cta::shared::CallPopup> _call;
            std::unique_ptr<cta::shared::Settings> _settings;
            bool _isCallable;
            bool _isPaused;
    };
}

#endif