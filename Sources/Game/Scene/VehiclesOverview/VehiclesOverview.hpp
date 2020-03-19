#ifndef VEHICLESOVERVIEW_HPP_
#define VEHICLESOVERVIEW_HPP_

#include <memory>
#include "AScene.hpp"
#include "MissionManager.hpp"

namespace cta::game::scene {

    class VehiclesOverview : public AScene {
        public:
            
            ~VehiclesOverview() = default;
            VehiclesOverview() = delete;
            VehiclesOverview(std::shared_ptr<cta::shared::MissionManager>);
            VehiclesOverview(const VehiclesOverview &) = delete;
            VehiclesOverview &operator=(const VehiclesOverview &) = delete;

            EReturn onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &) override final;
            void performScene() override final;
            void drawScene(std::shared_ptr<cta::engine::Window> &) override final;
        private:
            std::shared_ptr<cta::shared::MissionManager> _manager;
    };
}

#endif