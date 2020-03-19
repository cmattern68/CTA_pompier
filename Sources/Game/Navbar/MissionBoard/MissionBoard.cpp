#include "MissionBoard.hpp"

namespace cta::game::navbar
{
    MissionBoard::MissionBoard() {
        _bg = std::make_pair(
            std::make_unique<cta::engine::shape::RectangleShape>(
                std::make_pair(640, 59),
                std::make_pair(320, 40),
                std::make_tuple(30, 39, 56)
            ),
            std::make_unique<cta::engine::shape::RectangleShape>(
                std::make_pair(959, 59),
                std::make_pair(320, 40),
                std::make_tuple(30, 39, 56)
            )
        );
        (_bg.first)->setBorder(1, std::make_tuple(0, 0, 0));
        (_bg.second)->setBorder(1, std::make_tuple(0, 0, 0));
        _text = std::make_pair(
            std::make_unique<cta::engine::Text>(
                std::make_pair(650, 65),
                std::make_tuple(255, 255, 255),
                20,
                "Interventions en cours: 0",
                "Resources/Font/OpenSans.ttf",
                cta::engine::textStyle::BOLD
            ),
            std::make_unique<cta::engine::Text>(
                std::make_pair(969, 65),
                std::make_tuple(255, 255, 255),
                20,
                "Vehicules en intervention: 0",
                "Resources/Font/OpenSans.ttf",
                cta::engine::textStyle::BOLD
            )
        );
    }

    void MissionBoard::setMissionNb(std::size_t nb) {
        (_text.first)->setText("Interventions en cours: " + std::to_string(nb));
    }

    void MissionBoard::setInMissionVehiclesNb(std::size_t nb) {
        (_text.second)->setText("Vehicules en intervention: " + std::to_string(nb));
    }

    void MissionBoard::draw(std::shared_ptr<cta::engine::Window> &window) {
        window->draw((_bg.first)->getShape());
        window->draw((_bg.second)->getShape());
        window->draw((_text.first)->getText());
        window->draw((_text.second)->getText());
    }
}