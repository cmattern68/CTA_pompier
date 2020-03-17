#include "Sound.hpp"

namespace cta::engine {
    Sound::Sound(const std::string &soundPath, std::size_t sound) {        
        _sound.openFromFile(soundPath);                
        _sound.setVolume(sound);
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