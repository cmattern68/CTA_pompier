#ifndef MISSIONBOARD_HPP_
#define MISSIONBOARD_HPP_

#include "Text.hpp"
#include "RectangleShape.hpp"
#include "Window.hpp"

namespace cta::game::navbar {
    class MissionBoard {
        public:
            ~MissionBoard() = default;
            MissionBoard();
            MissionBoard(const MissionBoard &) = delete;
            MissionBoard &operator=(const MissionBoard &) = delete;
            
            void setMissionNb(std::size_t);
            void setInMissionVehiclesNb(std::size_t);

            void draw(std::shared_ptr<cta::engine::Window> &);
        private:
            std::pair<std::unique_ptr<cta::engine::shape::RectangleShape>, std::unique_ptr<cta::engine::shape::RectangleShape>> _bg;
            std::pair<std::unique_ptr<cta::engine::Text>, std::unique_ptr<cta::engine::Text>> _text;
    };
}

#endif