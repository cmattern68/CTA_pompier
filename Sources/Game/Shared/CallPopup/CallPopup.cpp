#include "CallPopup.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

namespace cta::shared {
    CallPopup::CallPopup() {
        std::string entrance("Appel 18 Entrant");
        std::string nb("0600000000");
        srand(time(NULL));
        _background = std::make_unique<cta::engine::shape::RectangleShape>(
            std::make_pair(1705, 720),
            std::make_pair(200, 250),
            std::make_tuple(61, 61, 61)
        );        
        if ((rand() % 10) >= 5)
            entrance = "Appel 112 Entrant";
        if ((rand() % 10) >= 5)
            nb = "0" + std::to_string((rand() % (596000000 - 130000000 + 1)) + 130000000);
        else
            nb = "0" + std::to_string((rand() % (700000000 - 600000000 + 1)) + 600000000);
        std::cout << "Phone Number: " << nb << std::endl;
        
    }

    void CallPopup::draw(std::shared_ptr<cta::engine::Window> &window) {        
        window->draw(_background->getShape());
    }
}