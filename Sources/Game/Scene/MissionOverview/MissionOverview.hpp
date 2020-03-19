#ifndef MISSIONOVERVIEW_HPP_
#define MISSIONOVERVIEW_HPP_

#include <memory>
#include "AScene.hpp"
#include "MissionManager.hpp"

namespace cta::game::scene {

    class MissionOverview : public AScene {
        public:
            
            ~MissionOverview() = default;
            MissionOverview() = delete;
            MissionOverview(std::shared_ptr<cta::shared::MissionManager>);
            MissionOverview(const MissionOverview &) = delete;
            MissionOverview &operator=(const MissionOverview &) = delete;

            EReturn onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &) override final;
            void performScene() override final;
            void drawScene(std::shared_ptr<cta::engine::Window> &) override final;
        private:
            std::shared_ptr<cta::shared::MissionManager> _manager;
    };
}

#endif