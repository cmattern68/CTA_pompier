#include "Core.hpp"
#include "Window.hpp"
#include "Game.hpp"
#include <memory>
#include <utility>
#include <tuple>

namespace cta {
    Core::Core() noexcept {

    }

    void Core::run(int ac, char **av) {
        (void)ac;
        (void)av;
        std::size_t i = 0;
        std::shared_ptr<cta::engine::Window> window = std::make_shared<cta::engine::Window>(std::make_pair(1920, 1080), "CTA Pompier");
        std::unique_ptr<cta::engine::Event> event = std::make_unique<cta::engine::Event>();
        std::unique_ptr<cta::game::Game> game = std::make_unique<cta::game::Game>(window);
        
        while (window->isOpen()) {
            while (window->pollEvent(event.get())) {
                if (event->getType() == cta::engine::Closed)
                    window->close();
            }
            game->run(i);
            window->clear(std::make_tuple(255, 255, 255));
            game->draw();
            window->display();
            ++i;
        }
    }
}