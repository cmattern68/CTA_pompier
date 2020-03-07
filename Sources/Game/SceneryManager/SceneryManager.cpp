#include "SceneryManager.hpp"

namespace cta::game
{
    SceneryManager::SceneryManager() {
        _sceneType = MISSION_OVERVIEW;
        _scene = std::make_unique<cta::game::scene::MissionOverview>();
    }

    void SceneryManager::setSceneType(const EScene &scene) {
        _sceneType = scene;
        switch (_sceneType)
        {
        case MISSION_OVERVIEW:
            _scene = std::make_unique<cta::game::scene::MissionOverview>();
            break;
        case SETTINGS:
            _scene = std::make_unique<cta::game::scene::Settings>();
            break;        
        default:
            break;
        }
    }
}
