#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "Window.hpp"
#include "Text.hpp"

namespace cta::game {

    enum EScene {
        MISSION_OVERVIEW,
        VEHICLES_OVERVIEW,
        RADIO_OVERVIEW,
        NONE,
    };

    class IScene {
        public:
            IScene(){}
            ~IScene() {};

            virtual void performScene() = 0;
            virtual void drawScene(std::shared_ptr<cta::engine::Window> &) = 0;
        protected:
            std::unique_ptr<cta::engine::Text> _text = 0;
    };
}

#endif