#ifndef ASCENE_HPP_
#define ASCENE_HPP_

#include <memory>
#include "IScene.hpp"

namespace cta::game {

    class AScene : public IScene {
        public:
            
            ~AScene() = default;
            AScene();
            AScene(EScene);
            AScene(const AScene &) = delete;
            AScene &operator=(const AScene &) = delete;            
    };
}

#endif