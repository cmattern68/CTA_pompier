#include "Game.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

namespace cta::game
{
    Game::Game(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &event) {        
        _window = window;        
        _event = event;        
        _navbar = std::make_unique<Navbar>();
        _manager = std::make_unique<SceneryManager>();
        _call = nullptr;
        _isCallable = true;

    }

    void Game::catchEvent() {
        if (_event->getType() == cta::engine::Closed)
            _window->close();
        if (!_isCallable && _call != nullptr) {
            std::string callReturn = _call->onEvent(_window);
            if (callReturn == "decline") {
                delete(_call.release());
                _isCallable = true;
                _call = nullptr;
            } else if (callReturn == "answer") {
                delete(_call.release());                
                _call = nullptr;
            }                
        }            
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
        int rd = rand() % 50;
        std::cout << rd << std::endl;
        srand(time(NULL));        
        if ((rd == 18)) {
            _call = std::make_unique<cta::shared::CallPopup>(_window);
            _isCallable = false;            
        }        
    }
}