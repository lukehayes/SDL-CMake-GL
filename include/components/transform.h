#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <iostream>
#include "component.h"
#include "math/vec2.h"

/**
 * Transform Transform stores position and rotation
 */
class Transform : public Component {
    public:
        Transform() {}
        virtual ~Transform() {}
        void update() {
            std::cout << "Updating Transform..." << std::endl;
        }
        
        /**
         * Position Getter
         *
         * @return Vec2<float>
         */
        V2i getPosition() const {
            return this->position;
        }

        /**
         * Position Setter
         *
         * @param x integer
         * @param y integer
         *
         * @return void
         */
        void setPosition(int x, int y) {
            this->position.x = x;
            this->position.y = y;
        }

        V2i position;
};


#endif
