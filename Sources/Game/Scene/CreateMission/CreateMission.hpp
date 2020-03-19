#ifndef CREATEMISSIONS_HPP_
#define CREATEMISSIONS_HPP_

#include <memory>
#include "AScene.hpp"
#include "RoundedRectangleShapeButton.hpp"

namespace cta::game::scene {

    class CreateMission : public AScene {
        public:
            
            ~CreateMission() = default;
            CreateMission();            
            CreateMission(const CreateMission &) = delete;
            CreateMission &operator=(const CreateMission &) = delete;

            EReturn onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &) override final;
            void performScene() override final;
            void drawScene(std::shared_ptr<cta::engine::Window> &) override final;
        private:
            std::unique_ptr<cta::engine::IButton> _close;
            std::unique_ptr<cta::engine::IButton> _save;
    };
}

#endif