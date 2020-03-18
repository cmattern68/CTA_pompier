#include "Menu.hpp"
#include <ctime>

namespace cta::game::scenerymanager
{
    Menu::Menu() {
        _hr = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(50, 180),
            std::make_pair(1820, 1),
            std::make_tuple(0, 0, 0)
        );
        _button.insert(
            std::make_pair(
                cta::game::MISSION_OVERVIEW,
                std::make_unique<cta::engine::button::RectangleShapeButton>(
                    std::make_pair(90, 140),
                    std::make_pair(290, 40),
                    "Synoptique des interventions",
                    true
                )
            )            
        );
        _button[cta::game::MISSION_OVERVIEW]->setBorder(1, {0, 0, 0});
        _button.insert(
            std::make_pair(
                cta::game::VEHICLES_OVERVIEW,
                std::make_unique<cta::engine::button::RectangleShapeButton>(
                    std::make_pair(380, 140),
                    std::make_pair(240, 40),
                    "Synoptique des moyens",
                    true
                )
            )            
        );
        _button[cta::game::VEHICLES_OVERVIEW]->setBorder(1, {0, 0, 0});
        _button.insert(
            std::make_pair(
                cta::game::RADIO_OVERVIEW,
                std::make_unique<cta::engine::button::RectangleShapeButton>(
                    std::make_pair(620, 140),
                    std::make_pair(70, 40),
                    "Radio",
                    true
                )
            )            
        );
        _button[cta::game::RADIO_OVERVIEW]->setBorder(1, {0, 0, 0});
        _timeText = nullptr;
        setTime();
        _timeText = std::make_unique<cta::engine::Text>(
            std::make_pair(1590, 145),
            std::make_tuple(0, 0, 0),
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
        return cta::game::NONE;
    }

    void Menu::setTime() {
        time_t tmm = time(0);
        _time = ctime(&tmm);
        if (_timeText != nullptr)
            _timeText->setText(_time);
    }

    void Menu::draw(std::shared_ptr<cta::engine::Window> &window) {        
        for (auto const &button : _button) {
            if ((button.second)->isHovered(cta::engine::Event::getMousePosition(window->getPosition())) && (button.second)->isClickable()) {
                (button).second->setBackground(std::make_tuple(236, 240, 241));
            } else {
                (button).second->setBackground(std::make_tuple(255, 255, 255));
            }
            (button.second)->draw(window);
        }
        setTime();
        window->draw(_timeText->getText());
        window->draw(_hr->getShape());
    }
}