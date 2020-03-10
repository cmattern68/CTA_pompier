#ifndef SPRITEBUTTON_HPP_
#define SPRITEBUTTON_HPP_

#include "Texture.hpp"
#include "IButton.hpp"

namespace cta::engine::button {

    class SpriteButton : public IButton {
        public:
            ~SpriteButton() = default;
            SpriteButton(std::pair<Pos, Pos>, std::string, Rect , std::pair<float, float>, bool);
            SpriteButton(const SpriteButton &) = delete;
            SpriteButton &operator=(const SpriteButton &) = delete;

            void setPos(std::pair<Pos, Pos>) override final;
            std::pair<Pos, Pos> getPos() override final { return _pos; };

            void draw(std::shared_ptr<cta::engine::Window> &) override final;

            /* Callback function */            
            bool isHovered(std::pair<std::size_t, std::size_t>) override final;
            bool isClicked() override final;
            bool isClickable() override final { return _isClickable; };
        private:
            bool _isClickable;
            std::pair<Pos, Pos> _pos;
            std::unique_ptr<Texture> _texture;

    };
}

#endif