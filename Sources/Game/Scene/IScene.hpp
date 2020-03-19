#ifndef ISCENE_HPP_
#define ISCENE_HPP_

#include "Window.hpp"
#include "Text.hpp"

namespace cta::game {

    enum EScene {
        MISSION_OVERVIEW,
        VEHICLES_OVERVIEW,
        RADIO_OVERVIEW,
        CREATE_MISSION,
        NONE,
    };

    enum EReturn {
        CLOSE,
        SUBMIT,
        NO,
    };

    class IScene {
        public:
            IScene(){}
            ~IScene() {};

            virtual EReturn onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &) = 0;
            virtual void performScene() = 0;
            virtual void drawScene(std::shared_ptr<cta::engine::Window> &) = 0;
        protected:
            std::unique_ptr<cta::engine::Text> _text = 0;
    };
}

#endif