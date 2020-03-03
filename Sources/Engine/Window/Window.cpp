#include "Window.hpp"

namespace cta::engine {
    Window::Window(std::pair<std::size_t, std::size_t> size, std::string name) {
        _size = size;
        _name = name;
        _window.create(sf::VideoMode(_size.first, _size.second), _name.c_str());
    }

    void Window::setSize(std::pair<std::size_t, std::size_t> size) {
        _size = size;
        _window.setSize(sf::Vector2u(_size.first, _size.second));
    }

    void Window::setTitle(const std::string &name) {
        _name = name;
        _window.setTitle(_name.c_str());
    }
}