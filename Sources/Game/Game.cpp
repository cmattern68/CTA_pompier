#include "Game.hpp"

namespace cta::game
{
    Game::Game(std::shared_ptr<cta::engine::Window> &window) {
        _window = window;
        _navbar = std::make_unique<Navbar>();
        _manager = std::make_unique<SceneryManager>();        
    }

    void Game::run(std::size_t i) {
        
    }

    void Game::draw() {
        _navbar->draw(_window);        
    }

    void Game::changeScene(EScene newScene) {
        _manager->setSceneType(newScene);
    }
}
