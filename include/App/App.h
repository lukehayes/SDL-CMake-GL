#ifndef APP_H
#define APP_H

#include "App/Window.h"
#include "GL/Shader.h"
#include "Platform/Resource.h"
#include "Graphics/Camera.h"
#include "Model/Model.h"

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

            Graphics::Camera cam;
            cam.Setup();

            shader.SetMat4("projection", cam.GetCombinedProjection());

            float counter = 0.0f;

            SDL_Event event;

            Model::Model model;

            float n = 100.0f;

            while (true) 
            {
                double current = SDL_GetTicks();
                double elapsed = current - previous;
                previous = current;
                lag += elapsed;

                //std::cout << position.x << " " << position.y << " " << position.z << std::endl;

                counter += 0.1;

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
				shader.SetMat4("projection", cam.GetCombinedProjection());
                std::cout << model.m_position.x << std::endl;

                model.m_position.x = std::cos(counter) * 2.0;
                model.m_position.y = std::sin(counter) / 1.0;
                model.m_position.z = std::sin(counter) * 10.0;

                //model = glm::rotate(model, glm::radians(45.0f), glm::vec3(0, 0, 1));
				model.GetMatrix() = glm::translate(model.GetMatrix(), model.m_position);

                shader.SetMat4("model", model.GetMatrix());
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
