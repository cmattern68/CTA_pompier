#ifndef SCENERY_MANAGER_HPP_
#define SCENERY_MANAGER_HPP_

#include "IScene.hpp"
#include "MissionOverview.hpp"
#include "VehiclesOverview.hpp"
#include "RadioOverview.hpp"
#include "CreateMission.hpp"
#include "RectangleShape.hpp"
#include "Menu.hpp"
#include "MissionManager.hpp"


namespace cta::game {    

    class SceneryManager {
        public:
            ~SceneryManager() = default;
            SceneryManager();
            SceneryManager(const SceneryManager &) = delete;
            SceneryManager &operator=(const SceneryManager &) = delete;

            EScene getSceneType() { return _sceneType; };
            void setSceneType(const EScene &);

            bool addEntry(const EScene &, const std::string &);
            bool hasEntry(const EScene &);
            bool removeEntry(const EScene &);

            const std::shared_ptr<cta::shared::MissionManager> MissionManager() { return _missionManager; };

            void onEvent(std::shared_ptr<cta::engine::Window> &, std::shared_ptr<cta::engine::Event> &);
            void draw(std::shared_ptr<cta::engine::Window> &);
        private:
            EScene _sceneType;
            std::unique_ptr<IScene> _scene;
            std::unique_ptr<cta::engine::shape::RectangleShape> _background;
            std::unique_ptr<cta::game::scenerymanager::Menu> _menu;
            std::shared_ptr<cta::shared::MissionManager> _missionManager;
    };
}

#endif