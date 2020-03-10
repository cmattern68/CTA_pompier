#ifndef SOUND_HPP_
#define SOUND_HPP_

#include <SFML/Audio.hpp>

namespace cta::engine {    

    class Sound {
        public:
            ~Sound() = default;
            Sound(const std::string &);
            Sound(const Sound &) = delete;
            Sound &operator=(const Sound &) = delete;
            void play();
            void stop();
            void pause();
        private:
            sf::Music _sound;
    };
}

#endif