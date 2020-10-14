#ifndef APP_H
#define APP_H

#include "App/Window.h"
#include "GL/Shader.h"
#include "Platform/Resource.h"
#include "Graphics/Camera.h"
#include "Graphics/Basic-Renderer.h"
#include "Model/Model.h"
#include "Util/Random.h"

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

            float counter = 0;

            std::vector<Model::Model> models;

            for(int i = 0; i<= 100; i++)
            {

                float x = Util::Random::GetFloat(-10,10.0);
                float y = Util::Random::GetFloat(-10,10.0);
                float z = -10.0;
                Model::Model m({x,y,z});

                models.push_back(m);

            }

            Model::Model model({ -4.0,0.0, -10.0});
            Model::Model model2({ 4.0,0.0, -10.0});
            Model::Model model3({ 4.0,1.0, -20.0});

            Graphics::Camera* cam = &m_renderer->m_camera;

            //models.push_back(model);
            //models.push_back(model2);
            //models.push_back(model3);

            SDL_Event event;

            while (true) 
            {
                double current = SDL_GetTicks();
                double elapsed = current - previous;
                previous = current;
                lag += elapsed;

                counter += 0.01;

            models.at(1).m_position.z = std::sin(counter) * 10.0;
            models.at(1).m_position.x = std::cos(counter) * 10.0;

            models.at(2).m_position.x = std::sin(counter) * 10.0;
            models.at(2).m_position.y = std::cos(counter) * 10.0;

            models.at(9).m_position.y = std::sin(counter) * 10.0;
            models.at(9).m_position.z = std::cos(counter) * 10.0;

                cam->LookAt({0,0,-50.0 + std::sin(counter) * 20.0});

				m_renderer->m_shader.SetMat4("projection", m_renderer->m_camera.GetProjectionMatrix());
				m_renderer->m_shader.SetMat4("view", m_renderer->m_camera.GetViewMatrix());


				m_renderer->m_shader.SetFloat("time", counter);

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

                m_renderer->Render(models);

                SDL_GL_SwapWindow(m_window.GetWindow());
            }
        }
        
        void Run(){
            this->Loop();
        }

        void Stop(){
            this->m_isRunning = false;
        }

        void SetRenderer(Graphics::BasicRenderer* renderer)
        {
            m_renderer = renderer;
        }

        private:
            Window m_window;
            bool m_isRunning = true;
            static const int MS_PER_UPDATE = 60;

            Graphics::BasicRenderer* m_renderer = nullptr;
    };
}

#endif
