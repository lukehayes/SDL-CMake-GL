#ifndef APP_H
#define APP_H

#include "App/Window.h"
#include "GL/Shader.h"
#include "Platform/Resource.h"

namespace App {

	class App {

        public:
		App(const int w, const int h, const char* title) : m_window(w,h,title) {}
        ~App() {
            SDL_Quit();
        }
        
        void Update(double dt) {
            //std::cout << "Update: " << dt << std::endl;
        }

        void Render() {
            //std::cout << "Render" << std::endl;
        }

        void Loop() 
        {
            double previous = SDL_GetTicks();
            double lag = 0.0;

            const std::string vshPath = ShaderResource("v.glsl");
            const std::string fshPath = ShaderResource("f.glsl");

            GL::Shader shader(vshPath.c_str(), fshPath.c_str());

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
                    this->Stop();
                    break;
                }

                while (lag >= MS_PER_UPDATE)
                {
                    // Update here
                    lag -= MS_PER_UPDATE;
                    Update(lag / 100);
                }

                // Render here
                glClearColor(0.0,0.2,0.5,1);
                glClear(GL_COLOR_BUFFER_BIT);

                //Render();
                shader.Use();
                glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


                SDL_GL_SwapWindow(m_window.GetWindow());
            }
        }
        
        void Run(){
            this->Loop();
        }

        void Stop(){
            this->m_isRunning = false;
        }

        private:
            Window m_window;
            bool m_isRunning = true;
            static const int MS_PER_UPDATE = 60;
    };
}

#endif
