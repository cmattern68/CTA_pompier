#include "SceneryManager.hpp"

namespace cta::game
{
    SceneryManager::SceneryManager() {
        _sceneType = MISSION_OVERVIEW;
        _scene = std::make_unique<cta::game::scene::MissionOverview>();
        _background = std::make_unique<cta::engine::shape::RoundedRectangleShape>(
            std::make_pair(50, 140),
            std::make_pair(1820, 790),
            std::make_tuple(255, 255, 255),
            15.0
        );
        _background->setBorder(
            1,
            std::make_tuple(0, 0, 0)
        );
    }

    void SceneryManager::setSceneType(const EScene &scene) {
        _sceneType = scene;        
        switch (_sceneType)
        {
        case MISSION_OVERVIEW:
            _scene = std::make_unique<cta::game::scene::MissionOverview>();
            break;
        case VEHICLES_OVERVIEW:
            _scene = std::make_unique<cta::game::scene::VehiclesOverview>();
            break;
        case RADIO_OVERVIEW:
            _scene = std::make_unique<cta::game::scene::RadioOverview>();
            break;
        default:
            break;
        }
    }

    void SceneryManager::draw(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_background->getShape());
        _scene->drawScene(window);
    }
}
