#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "Window.hpp"
#include <iostream>

namespace cta::game {

    enum EScene {
        MISSION_OVERVIEW,
        SETTINGS
    };

    class IScene {
        public:
            IScene(){}
            ~IScene() {};

            virtual void performScene() = 0;
            virtual void drawScene(std::shared_ptr<cta::engine::Window> &) = 0;
    };
}

#endif