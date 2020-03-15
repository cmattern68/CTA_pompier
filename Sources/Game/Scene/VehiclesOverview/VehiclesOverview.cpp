#include "VehiclesOverview.hpp"

namespace cta::game::scene
{
    VehiclesOverview::VehiclesOverview() {        
        _text = std::make_unique<cta::engine::Text>(
            std::make_pair(60, 150),
            std::make_tuple(0, 0, 0),
            18,
            "VehiclesOverview",
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::REGULAR
        );
    }

    void VehiclesOverview::performScene() {

    }

    void VehiclesOverview::drawScene(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_text->getText());
    }
}
