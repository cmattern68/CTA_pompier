#ifndef RADIOOVERVIEW_HPP_
#define RADIOOVERVIEW_HPP_

#include <memory>
#include "AScene.hpp"

namespace cta::game::scene {

    class RadioOverview : public AScene {
        public:
            
            ~RadioOverview() = default;
            RadioOverview();            
            RadioOverview(const RadioOverview &) = delete;
            RadioOverview &operator=(const RadioOverview &) = delete;

            EReturn onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &) override final;
            void performScene() override final;
            void drawScene(std::shared_ptr<cta::engine::Window> &) override final;
    };
}

#endif