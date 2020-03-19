#include "Core.hpp"
#include "Window.hpp"
#include "Game.hpp"
#include "Errors.hpp"
#include <memory>
#include <utility>
#include <tuple>

namespace cta {
    Core::Core() noexcept {

    }

    void Core::run(const int ac, const char * const *av, const char * const* env) {        
        if (ac > 1 || av[1] != NULL)
            throw SystemError {"Cannot run the program with argument."};
        if (env[0] == NULL)
            throw SystemError {"Cannot run the program without environment"};        
        std::shared_ptr<cta::engine::Window> window = std::make_shared<cta::engine::Window>(std::make_pair(1920, 1080), "CTA Pompier");
        std::shared_ptr<cta::engine::Event> event = std::make_shared<cta::engine::Event>();
        std::unique_ptr<cta::game::Game> game = std::make_unique<cta::game::Game>(window, event);        

        while (window->isOpen()) {
            while (window->pollEvent(event.get())) {                
                game->catchEvent();
            }
            game->run();
            window->clear(std::make_tuple(21, 27, 40));
            game->draw();
            window->display();            
        }
    }
}