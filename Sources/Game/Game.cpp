#include "Game.hpp"
#include <time.h>
#include <stdlib.h>

namespace cta::game
{
    Game::Game(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &event) {        
        _window = window;        
        _event = event;        
        _navbar = std::make_unique<Navbar>();
        _manager = std::make_unique<SceneryManager>();
        _call = nullptr;
        _isCallable = true;
        _isPaused = false;
        _settings = std::make_unique<cta::shared::Settings>();

    }

    void Game::catchEvent() {
        if (_event->getType() == cta::engine::Closed)
            _window->close();
        if (_navbar->onEvent(_window, _event) && !_isPaused) {
            _isPaused = true;
        }
        if (!_isCallable && _call != nullptr && !_isPaused) {
            std::string callReturn = _call->onEvent(_window, _event);            
            if (callReturn == "decline") {
                delete(_call.release());
                _isCallable = true;
                _call = nullptr;                
            } else if (callReturn == "answer") {
                callAnswer();
                delete(_call.release());                
                _call = nullptr;
            }
        }
        if (_isPaused && _settings->isOpen()) {
            _settings->onEvent(_window, _event);
            _isPaused = !_settings->close(_window, _event);
            if (!_isPaused && _call != nullptr)
                _call->play();
        }
        _manager->onEvent(_window, _event);
    }

    void Game::run() {
        if (!_isPaused) {
            if (_isCallable) {
                dispatchUserCall();
            }                
        } else if (!_settings->isOpen()) {
            if (_call != nullptr)
                _call->pause();
            _settings->open();
        }        
        if (isOnCall())
            _isCallable = false;
        else
            _isCallable = true;
    }

    void Game::draw() {
        updateMissionBoard();
        _navbar->draw(_window);
        _manager->draw(_window);
        if (!_isCallable && _call != nullptr)
            _call->draw(_window);
        if (_isPaused)
            _settings->draw(_window);
    }

    void Game::dispatchUserCall() {                
        srand(time(NULL));                
        if ((rand() % 30) == 18) {
            _call = std::make_unique<cta::shared::CallPopup>(_window, _settings->getSound());
            _isCallable = false;
        }        
    }

    void Game::callAnswer() {
        bool success = _manager->addEntry(cta::game::CREATE_MISSION, "Nouvelle Intervention *");
        if (success)
            _manager->setSceneType(cta::game::CREATE_MISSION);        
    }

    void Game::updateMissionBoard() {
        _navbar->updateMission(_manager->MissionManager()->getMission());
    }

    bool Game::isOnCall() {        
        if (_manager->hasEntry(cta::game::CREATE_MISSION) || _call != nullptr)
            return true;
        return false;
    }
}