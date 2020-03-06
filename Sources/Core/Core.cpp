#include "Core.hpp"
#include "Window.hpp"
#include "RectangleShape.hpp"
#include "CircleShape.hpp"
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

        std::unique_ptr<cta::engine::shape::RectangleShape> rectangle = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(0, 0),
            std::make_pair(1920, 100),
            std::make_tuple(254, 27, 0)
        );

        std::unique_ptr<cta::engine::shape::CircleShape> circle = std::make_unique<cta::engine::shape::CircleShape>(
            std::make_pair(140, 220),
            50,
            std::make_tuple(254, 27, 0)
        );
        while (window->isOpen()) {
            while (window->pollEvent(event.get())) {
                if (event->getType() == cta::engine::Closed)
                    window->close();
            }
            window->clear(std::make_tuple(255, 255, 255));            

            window->draw(rectangle->getShape());
            window->draw(circle->getShape());

            window->display();
            ++i;
        }
    }
}