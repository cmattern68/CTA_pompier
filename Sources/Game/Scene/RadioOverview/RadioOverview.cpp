#include "RadioOverview.hpp"

namespace cta::game::scene
{
    RadioOverview::RadioOverview() {        
        _text = std::make_unique<cta::engine::Text>(
            std::make_pair(60, 200),
            std::make_tuple(0, 0, 0),
            18,
            "RadioOverview",
            "Resources/Font/OpenSans.ttf",
            cta::engine::textStyle::REGULAR
        );
    }

    void RadioOverview::performScene() {

    }

    EReturn RadioOverview::onEvent(std::shared_ptr<cta::engine::Window> &window, std::shared_ptr<cta::engine::Event> &evt) {
        (void)window;
        (void)evt;
        return EReturn::NO;
    }

    void RadioOverview::drawScene(std::shared_ptr<cta::engine::Window> &window) {
        window->draw(_text->getText());
    }
}
