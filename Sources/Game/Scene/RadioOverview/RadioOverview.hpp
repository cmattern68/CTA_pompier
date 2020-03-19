#ifndef RADIOOVERVIEW_HPP_
#define RADIOOVERVIEW_HPP_

#include <memory>
#include "AScene.hpp"
#include "MissionManager.hpp"

namespace cta::game::scene {

    class RadioOverview : public AScene {
        public:
            
            ~RadioOverview() = default;
            RadioOverview() = delete;
            RadioOverview(std::shared_ptr<cta::shared::MissionManager>);
            RadioOverview(const RadioOverview &) = delete;
            RadioOverview &operator=(const RadioOverview &) = delete;

            EReturn onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &) override final;
            void performScene() override final;
            void drawScene(std::shared_ptr<cta::engine::Window> &) override final;
        private:
            std::shared_ptr<cta::shared::MissionManager> _manager;
    };
}

#endif