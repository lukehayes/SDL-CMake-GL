#ifndef GRAPHICS_CAMERA_H
#define GRAPHICS_CAMERA_H

#include "../Util/glm.h"


namespace Graphics {

	class Camera {
	public:
        Camera() : m_position(0.0,0.0,3.0f)  
        {
            Setup();
        }

		Camera(const Camera& cam) 
        {
            this->m_position = cam.m_position;
            this->m_projection = cam.m_projection;
            this->m_view = cam.m_view;
            this->m_up = cam.m_up;
            this->m_target = cam.m_target;
        }

		Camera(const glm::vec3& pos) : m_position(pos) 
        {
            Setup();
        }

		~Camera() {}
		
		/**
		Setup the projection, view matricies, orientation etc
		*/
		void Setup() {
			m_projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
            m_view = glm::lookAt(m_position, m_target, m_up);
		}

        inline glm::mat4 GetProjectionMatrix() const
        {
            return this->m_projection;
        }

        inline glm::mat4 GetViewMatrix() const
        {
            return this->m_view;
        }

		glm::mat4 GetCombinedProjection() {
			return glm::matrixCompMult(m_projection, m_view);
		}

        void LookAt(const glm::vec3& position)
        {
            this->m_view = glm::lookAt(position, m_target, m_up);
        }

        void Update(double dt) {
            this->LookAt(m_position);
        }


		glm::vec3 m_position;
		glm::mat4 m_projection = glm::mat4(1.0f);
		glm::mat4 m_view =	glm::mat4(1.0f);
        glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 m_target = glm::vec3(0.0f, 0.0f, 0.0f);
	};
}

#endif // !GRAPHICS_RENDERER_H
