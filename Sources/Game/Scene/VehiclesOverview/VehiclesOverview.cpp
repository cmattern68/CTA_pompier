#include "VehiclesOverview.hpp"

namespace cta::game::scene
{
    VehiclesOverview::VehiclesOverview(std::shared_ptr<cta::shared::MissionManager> manager) {        
        _text = std::make_unique<cta::engine::Text>(
            std::make_pair(60, 200),
            std::make_tuple(0, 0, 0),
            18,
            "VehiclesOverview",
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::REGULAR
        );
        _manager = manager;
    }

    void VehiclesOverview::performScene() {

    }

    EReturn VehiclesOverview::onEvent(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {
        (void)window;
        (void)evt;
        return EReturn::NO;
    }

    void VehiclesOverview::drawScene(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_text->getText());
    }
}
