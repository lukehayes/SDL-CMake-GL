#ifndef APP_H
#define APP_H

#include "App/Window.h"
#include "GL/Shader.h"
#include "Platform/Resource.h"
#include "Graphics/Camera.h"
#include "Graphics/Basic-Renderer.h"
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

            float counter = 0.0f;

            SDL_Event event;

            while (true) 
            {
                double current = SDL_GetTicks();
                double elapsed = current - previous;
                previous = current;
                lag += elapsed;

				m_renderer->m_shader.SetMat4("projection", m_renderer->m_camera.GetProjectionMatrix());
				m_renderer->m_shader.SetMat4("view", m_renderer->m_camera.GetViewMatrix());
				m_renderer->m_shader.SetMat4("model", m_renderer->m_model.GetMatrix());

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

                m_renderer->Render();

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
