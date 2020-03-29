#ifndef PLAYER_H
#define PLAYER_H

#include "components/transform.h"
#include <cmath>

class Player {
    public:
        Player() {
            this->transform.position.x = 300;
            this->transform.position.y = 300;
        }
        ~Player() {}

        void update() {
            static int c;
            c += 1;
            int n = 2;
            //transform.setPosition(std::sin(c) * n, std::cos(c) * n);
        }

        Transform transform;
};

#endif
