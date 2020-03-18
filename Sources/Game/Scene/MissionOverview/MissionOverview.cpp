#include "MissionOverview.hpp"

namespace cta::game::scene
{
    MissionOverview::MissionOverview() {        
        _text = std::make_unique<cta::engine::Text>(
            std::make_pair(60, 200),
            std::make_tuple(0, 0, 0),
            18,
            "MissionOverview",
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::REGULAR
        );
    }

    void MissionOverview::performScene() {

    }

    void MissionOverview::drawScene(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_text->getText());
    }
}
