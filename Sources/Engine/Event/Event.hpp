#include <SFML/Graphics.hpp>

namespace cta::engine {

    enum {
        Closed = sf::Event::Closed,
    };

    class Event {

        public:
            Event();
            Event(const Event &) = delete;
            ~Event() = default;
            sf::Event &getEvent() { return _event; };
            std::size_t getType() { return _event.type; }
        
        private:
            sf::Event _event;
    };
}