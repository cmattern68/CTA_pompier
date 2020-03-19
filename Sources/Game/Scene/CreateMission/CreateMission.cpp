#include "CreateMission.hpp"
#include <iostream>

namespace cta::game::scene
{
    CreateMission::CreateMission(std::shared_ptr<cta::shared::MissionManager> manager) {                
        _close = std::make_unique<cta::engine::button::RoundedRectangleShapeButton>(
            std::make_pair(1780, 840),
            std::make_pair(110 ,50),
            std::make_tuple(188, 21, 28),
            "Annuler",
            true
        );

        _save = std::make_unique<cta::engine::button::RoundedRectangleShapeButton>(
            std::make_pair(1615, 840),
            std::make_pair(155 ,50),
            std::make_tuple(39, 174, 96),
            "Declancher",
            true
        );
        _manager = manager;        
    }

    void CreateMission::performScene() {

    }

    EReturn CreateMission::onEvent(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {
        if (_close->isClicked(window, evt)) {            
            return EReturn::CLOSE;
        } else if (_save->isClicked(window, evt)) {
            return EReturn::SUBMIT;
        }
        return EReturn::NO;
    }

    void CreateMission::drawScene(std::shared_ptr<cta::engine::Window> &window) {        
        _close->draw(window);
        _save->draw(window);
    }
}