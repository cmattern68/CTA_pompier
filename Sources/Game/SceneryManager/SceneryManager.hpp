#ifndef SCENERY_MANAGER_HPP_
#define SCENERY_MANAGER_HPP_

#include "IScene.hpp"
#include "MissionOverview.hpp"
#include "Settings.hpp"

namespace cta::game {    

    class SceneryManager {
        public:
            ~SceneryManager() = default;
            SceneryManager();
            SceneryManager(const SceneryManager &) = delete;
            SceneryManager &operator=(const SceneryManager &) = delete;

            EScene getSceneType() { return _sceneType; };
            void setSceneType(const EScene &scene);
        private:
            EScene _sceneType;
            std::unique_ptr<IScene> _scene;
    };
}

#endif