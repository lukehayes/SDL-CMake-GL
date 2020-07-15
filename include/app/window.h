#ifndef APP_WINDOW_H
#define APP_WINDOW_H

namespace App {

	class Window {
        public:
		Window(const int width, const int height, const char* title ) 
            : m_width(width), m_height(height), m_title(title)
        {

            if (SDL_Init(SDL_INIT_VIDEO) < 0) {
                std::cout << "SDL Not Initialized!" << std::endl;
            }

            SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 3  );
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 3  );
            SDL_GL_SetAttribute( SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE  );

            m_window = SDL_CreateWindow(
                    m_title,
                0,0,m_width, m_height,
                SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE
            );

            m_context = SDL_GL_CreateContext(m_window);

        }
        ~Window() {
            SDL_GL_DeleteContext(m_context);
            SDL_DestroyWindow(m_window);
        }

        SDL_Window* getWindow() const {
            return m_window;
        }

        private:

        int m_width;
        int m_height;
        const char* m_title;
        SDL_Window* m_window;
        SDL_GLContext m_context;
	};
}

#endif
