#include "Core.hpp"
#include "Window.hpp"
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
        std::unique_ptr<cta::engine::Window> window = std::make_unique<cta::engine::Window>(std::make_pair(1920, 1080), "CTA Pompier");
        std::unique_ptr<cta::engine::Event> event = std::make_unique<cta::engine::Event>();
        while (window->isOpen()) {
            while (window->pollEvent(event.get())) {
                if (event->getType() == cta::engine::Closed)
                    window->close();
            }
            window->clear(std::make_tuple(255, 255, 255));
            window->display();
            ++i;
        }
    }
}