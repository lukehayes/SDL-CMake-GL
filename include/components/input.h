#ifndef INPUT_H
#define INPUT_H

#include "components/component.h"
#include <iostream>
#include "SDL.h"

class Input {
    public:
        Input() {}
        ~Input() {}

        void update() {
            SDL_Event event;
            while (SDL_PollEvent(&event)) {
                switch (event.type) {
                    case SDL_KEYDOWN:
                        std::cout << "Keyboard" << std::endl;
                        break;
                    default:
                        std::cout << "None" << std::endl;
                        
                }
            }
        }
};

#endif
