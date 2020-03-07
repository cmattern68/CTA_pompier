#include "MissionOverview.hpp"

namespace cta::game::scene
{
    MissionOverview::MissionOverview() {
        std::cout << "New MissionOverview" << std::endl;
    }

    void MissionOverview::performScene() {

    }

    void MissionOverview::drawScene(std::shared_ptr<cta::engine::Window> &window) {
        (void)window;
    }
}
