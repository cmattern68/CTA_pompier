#ifndef IBUTTON_HPP_
#define IBUTTON_HPP_

#include "Window.hpp"

namespace cta::engine {    

    struct Pos {
        std::size_t x;
        std::size_t y;
    };

    class IButton {
        public:
            virtual void setPos(std::pair<Pos, Pos>) = 0;
            virtual std::pair<Pos, Pos> getPos() = 0;
            virtual void draw(std::shared_ptr<cta::engine::Window> &) = 0;

            /* Callback function */            
            virtual bool isHovered(std::pair<std::size_t, std::size_t>) = 0;
            virtual bool isClicked() = 0;
            virtual bool isClickable() = 0;
    };
}

#endif