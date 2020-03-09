#ifndef CALLPOPUP_HPP_
#define CALLPOPUP_HPP_

#include <vector>
#include "Window.hpp"
#include "RectangleShape.hpp"
#include "Text.hpp"

namespace cta::shared {    

    class CallPopup {
        public:
            ~CallPopup() = default;
            CallPopup();
            CallPopup(const CallPopup &) = delete;
            CallPopup &operator=(const CallPopup &) = delete;
            void draw(std::shared_ptr<cta::engine::Window> &);
        private:
            std::unique_ptr<cta::engine::shape::RectangleShape> _background;
            std::vector<std::unique_ptr<cta::engine::Text>> _text;
    };
}

#endif