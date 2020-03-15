#ifndef VEHICLESOVERVIEW_HPP_
#define VEHICLESOVERVIEW_HPP_

#include <memory>
#include "AScene.hpp"

namespace cta::game::scene {

    class VehiclesOverview : public AScene {
        public:
            
            ~VehiclesOverview() = default;
            VehiclesOverview();            
            VehiclesOverview(const VehiclesOverview &) = delete;
            VehiclesOverview &operator=(const VehiclesOverview &) = delete;

            void performScene() override final;
            void drawScene(std::shared_ptr<cta::engine::Window> &) override final;
    };
}

#endif