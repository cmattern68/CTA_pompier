#include <utility>
#include <string>
#include <SFML/Graphics.hpp>
#include <memory>
#include <tuple>
#include "Event.hpp"

namespace cta::engine {
    class Window {
        public:
            Window(std::pair<std::size_t, std::size_t>, std::string);
            Window(const Window &) = delete;
            ~Window() = default;
            
            void setSize(std::pair<std::size_t, std::size_t>);
            std::pair<std::size_t, std::size_t> getSize() { return _size; };

            void setTitle(const std::string &);
            const std::string getTitle() { return _name; };            

            bool isOpen() { return _window.isOpen(); }
            bool pollEvent(Event *evt) { return _window.pollEvent(evt->getEvent()); }
            void close() { _window.close(); }
            void clear(std::tuple<unsigned int, unsigned int, unsigned int> color) { _window.clear(sf::Color(std::get<0>(color), std::get<1>(color), std::get<2>(color))); };
            void display() { _window.display(); };
        
        private:
            std::pair<std::size_t, std::size_t> _size;
            std::string _name;
            sf::RenderWindow _window;
    };
}