#ifndef APP_H
#define APP_H

#include "app/window.h"

namespace App {

	class App {

        public:
		App(const int w, const int h, const char* title) : m_window(w,h,title) {}
        ~App() {
            SDL_Quit();
        }
        
        void update(double dt) {
            std::cout << "Update: " << dt << std::endl;
        }

        void render() {
            std::cout << "Render" << std::endl;
        }


        void loop() 
        {
            const int MS_PER_UPDATE = 30;
            double previous = SDL_GetTicks();
            double lag = 0.0;

            SDL_Event event;

            while (true) 
            {
                double current = SDL_GetTicks();
                double elapsed = current - previous;
                previous = current;
                lag += elapsed;

                // processInput();

                SDL_PollEvent(&event);
                if (event.type == SDL_QUIT) {
                    this->stop();
                    break;
                }

                while (lag >= MS_PER_UPDATE)
                {
                    // Update here
                    lag -= MS_PER_UPDATE;
                    update(lag / 100);
                }

                // Render here
                glClearColor(0.0,0.5,0.5,1);
                glClear(GL_COLOR_BUFFER_BIT);

                render();

                SDL_GL_SwapWindow(m_window.getWindow());
            }
        }
        
        void run(){
            this->loop();
        }

        void stop(){
            this->m_isRunning = false;
        }

        private:
            Window m_window;
            bool m_isRunning = true;
    };
}

#endif
