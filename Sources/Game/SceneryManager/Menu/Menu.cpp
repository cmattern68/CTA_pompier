#include "Menu.hpp"
#include <ctime>

namespace cta::game::scenerymanager
{
    Menu::Menu() {
        _button.insert(
            std::make_pair(
                cta::game::MISSION_OVERVIEW,
                std::make_unique<cta::engine::button::RectangleShapeButton>(
                    std::make_pair(20, 140),
                    std::make_pair(290, 40),
                    std::make_tuple(21, 27, 40),
                    "Synoptique des interventions",
                    true
                )
            )            
        );        
        _button.insert(
            std::make_pair(
                cta::game::VEHICLES_OVERVIEW,
                std::make_unique<cta::engine::button::RectangleShapeButton>(
                    std::make_pair(310, 140),
                    std::make_pair(240, 40),
                    std::make_tuple(21, 27, 40),
                    "Synoptique des moyens",
                    true
                )
            )            
        );        
        _button.insert(
            std::make_pair(
                cta::game::RADIO_OVERVIEW,
                std::make_unique<cta::engine::button::RectangleShapeButton>(
                    std::make_pair(550, 140),
                    std::make_pair(70, 40),
                    std::make_tuple(21, 27, 40),
                    "Radio",
                    true
                )
            )            
        );        
        _timeText = nullptr;
        setTime();
        _timeText = std::make_unique<cta::engine::Text>(
            std::make_pair(1660, 145),
            std::make_tuple(255, 255, 255),
            20,
            _time,
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::REGULAR
        );
    }

    cta::game::EScene Menu::onEvent(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {        
        for (auto const &button : _button)
            if ((button.second)->isClicked(window, evt))
                return button.first;                    
        return cta::game::EScene::NONE;
    }

    bool Menu::insert(const cta::game::EScene &scene, const std::string &name) {
        if (_button.find(scene) == _button.end()) {
            _button.insert(
                std::make_pair(
                    scene,
                    std::make_unique<cta::engine::button::RectangleShapeButton>(
                        std::make_pair(620, 140),
                        std::make_pair(230, 40),
                        std::make_tuple(21, 27, 40),
                        name,
                        true
                    )
                )            
            );            
            return true;
        }
        return false;
    }

    bool Menu::remove(const cta::game::EScene &scene) {
        if (_button.find(scene) != _button.end()) {
            _button.erase(scene);
            return true;
        }
        return false;
    }

    void Menu::setTime() {
        time_t tmm = time(0);
        _time = ctime(&tmm);
        if (_timeText != nullptr)
            _timeText->setText(_time);
    }

    void Menu::draw(std::shared_ptr<cta::engine::Window> &window, const EScene &scene) {        
        for (auto const &button : _button) {                        
            if (button.first == scene) {
                (button).second->setBackground(std::make_tuple(255, 131, 0));
            } else if ((button.second)->isHovered(cta::engine::Event::getMousePosition(window->getPosition())) && (button.second)->isClickable()) {
                (button).second->setBackground(std::make_tuple(117, 21, 30));
            } else {
                (button).second->setBackground(std::make_tuple(21, 27, 40));
            }
            (button.second)->draw(window);
        }
        setTime();
        window->draw(_timeText->getText());        
    }
}