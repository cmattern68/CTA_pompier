#include "Game.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

namespace cta::game
{
    Game::Game(std::shared_ptr<cta::engine::Window> &window) {
        _window = window;
        _navbar = std::make_unique<Navbar>();
        _manager = std::make_unique<SceneryManager>();
        _call = nullptr;
        _isCallable = true;

    }

    void Game::run() {
        if (_isCallable)
            dispatchUserCall();
    }

    void Game::draw() {
        _navbar->draw(_window);
        if (!_isCallable && _call != nullptr)
            _call->draw(_window);        
    }

    void Game::switchScene(EScene newScene) {
        _manager->setSceneType(newScene);
    }

    void Game::dispatchUserCall() {
        srand(time(NULL));        
        if ((rand() % 50) == 18) {
            _call = std::make_unique<cta::shared::CallPopup>();
            _isCallable = false;            
        }        
    }
}