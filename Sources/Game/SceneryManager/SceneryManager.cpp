#include "SceneryManager.hpp"

namespace cta::game
{
    SceneryManager::SceneryManager() {
        _sceneType = MISSION_OVERVIEW;        
        _background = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(20, 180),
            std::make_pair(1880, 720),
            std::make_tuple(221, 224, 231)
        );
        _background->setBorder(
            1,
            std::make_tuple(0, 0, 0)
        );
        _menu = std::make_unique<cta::game::scenerymanager::Menu>();
        _missionManager = std::make_shared<cta::shared::MissionManager>();
        _scene = std::make_unique<cta::game::scene::MissionOverview>(_missionManager);
    }

    void SceneryManager::setSceneType(const EScene &scene) {
        _sceneType = scene;        
        switch (_sceneType)
        {
        case MISSION_OVERVIEW:
            _scene = std::make_unique<cta::game::scene::MissionOverview>(_missionManager);
            break;
        case VEHICLES_OVERVIEW:
            _scene = std::make_unique<cta::game::scene::VehiclesOverview>(_missionManager);
            break;
        case RADIO_OVERVIEW:
            _scene = std::make_unique<cta::game::scene::RadioOverview>(_missionManager);
            break;
        case CREATE_MISSION:
            _scene = std::make_unique<cta::game::scene::CreateMission>(_missionManager);
            break;
        default:
            break;
        }
    }

    bool SceneryManager::addEntry(const EScene &scene, const std::string &name) {
        return _menu->insert(scene, name);
    }    

    bool SceneryManager::hasEntry(const EScene &scene) {
        if (scene == _sceneType)
            return true;
        return false;
    }

    bool SceneryManager::removeEntry(const EScene &scene) {
        if (_menu->remove(scene)) {
            setSceneType(MISSION_OVERVIEW);
        }
        return false;
    }

    void SceneryManager::onEvent(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {        
        EScene newScene = _menu->onEvent(window, evt);
        if (newScene != cta::game::EScene::NONE)
            setSceneType(newScene);
        EReturn onEvent = _scene->onEvent(window, evt);
        if (onEvent == EReturn::CLOSE || onEvent == EReturn::SUBMIT) {
            removeEntry(_sceneType);
            if (onEvent == EReturn::SUBMIT)
                _missionManager->addMission();
        }            
    }

    void SceneryManager::draw(std::shared_ptr<cta::engine::Window> &window) {        
        window->draw(_background->getShape());        
        _menu->draw(window, _sceneType);
        _scene->drawScene(window);
    }
}
