#ifndef ASHAPE_HPP_
#define ASHAPE_HPP_

#include <tuple>

namespace cta::engine {

    #ifndef ENUM_SHAPE_TYPE
    #define ENUM_SHAPE_TYPE
    enum Type {        
        RECTANGLE_SHAPE
    };
    #endif

    class AShape {

        public:
            AShape() = default;            
            AShape(const AShape &) = delete;
            ~AShape() = default;

            void setType(unsigned short int type) { _type = type; };
            unsigned short int getType() { return _type; };

            std::pair<std::size_t, std::size_t> getPos() { return std::make_pair(_position.x, _position.y); };

        protected:
            unsigned short int _type;
            sf::Vector2f _position;            
            sf::RectangleShape _rectangleShape;
            std::tuple<unsigned short int, unsigned short int, unsigned short int> _color;
    };
}

#endif