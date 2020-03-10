#include "Sound.hpp"

namespace cta::engine {
    Sound::Sound(const std::string &soundPath) {        
        _sound.openFromFile(soundPath);                
        _sound.setVolume(100);
        _sound.setPitch(2);
        _sound.setLoop(true);
        _sound.play();
    }

    void Sound::play() {
        _sound.play();
    }

    void Sound::stop() {
        _sound.stop();
    }

    void Sound::pause() {
        _sound.pause();
    }
}