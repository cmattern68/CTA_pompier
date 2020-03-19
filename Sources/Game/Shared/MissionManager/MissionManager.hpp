#ifndef MISSIONMANAGER_HPP_
#define MISSIONMANAGER_HPP_

#include "Window.hpp"

namespace cta::shared {
    class MissionManager {
        public:
            ~MissionManager() = default;
            MissionManager();
            MissionManager(const MissionManager &) = delete;
            MissionManager &operator=(const MissionManager &) = delete;

            std::size_t getMission() { return _missions; };
            void addMission() { _missions += 1; };
            void removeMission() { _missions -= 1; };
        private:
            std::size_t _missions;
    };
}

#endif