#ifndef SCENERY_MANAGER_HPP_
#define SCENERY_MANAGER_HPP_

#include "IScene.hpp"
#include "MissionOverview.hpp"
#include "VehiclesOverview.hpp"
#include "RadioOverview.hpp"
#include "RectangleShape.hpp"

namespace cta::game {    

    class SceneryManager {
        public:
            ~SceneryManager() = default;
            SceneryManager();
            SceneryManager(const SceneryManager &) = delete;
            SceneryManager &operator=(const SceneryManager &) = delete;

            EScene getSceneType() { return _sceneType; };
            void setSceneType(const EScene &);

            void draw(std::shared_ptr<cta::engine::Window> &);
        private:
            EScene _sceneType;
            std::unique_ptr<IScene> _scene;
            std::unique_ptr<cta::engine::shape::RectangleShape> _background;
    };
}

#endif