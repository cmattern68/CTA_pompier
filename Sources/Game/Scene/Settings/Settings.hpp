#ifndef SETTINGS_HPP_
#define SETTINGS_HPP_

#include <memory>
#include "AScene.hpp"

namespace cta::game::scene {

    class Settings : public AScene {
        public:
            
            ~Settings() = default;
            Settings();            
            Settings(const Settings &) = delete;
            Settings &operator=(const Settings &) = delete;

            void performScene() override final;
            void drawScene(std::shared_ptr<cta::engine::Window> &) override final;
    };
}

#endif