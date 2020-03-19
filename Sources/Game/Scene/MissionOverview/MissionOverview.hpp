#ifndef MISSIONOVERVIEW_HPP_
#define MISSIONOVERVIEW_HPP_

#include <memory>
#include "AScene.hpp"

namespace cta::game::scene {

    class MissionOverview : public AScene {
        public:
            
            ~MissionOverview() = default;
            MissionOverview();            
            MissionOverview(const MissionOverview &) = delete;
            MissionOverview &operator=(const MissionOverview &) = delete;

            EReturn onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &) override final;
            void performScene() override final;
            void drawScene(std::shared_ptr<cta::engine::Window> &) override final;
    };
}

#endif