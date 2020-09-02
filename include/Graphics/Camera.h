#ifndef GRAPHICS_CAMERA_H
#define GRAPHICS_CAMERA_H

#include "../Util/glm.h"


namespace Graphics {

	class Camera {
	public:
		Camera() : m_position(0.0,0.0,-3.0f)  {}
		Camera(const Camera& cam) {}
		Camera(const glm::vec3& pos) : m_position(pos) {}
		~Camera() {}
		
		/**
		Setup the projection, view matricies, orientation etc
		*/
		void Setup() {
			m_projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
            m_view = glm::lookAt(m_position, m_camTarget, m_up);
		}

		glm::mat4 GetCombinedProjection() {
			return m_projection * m_view;
		}

		void Update(double dt) {}

		glm::vec3 m_position = glm::vec3(0.0f);
		glm::mat4 m_projection = glm::mat4(1.0f);
		glm::mat4 m_view =	glm::mat4(1.0f);
        glm::vec3 m_up = glm::vec3(0.0f, 1.0f, 0.0f);
		glm::vec3 m_camTarget = glm::vec3(0.0f, 0.0f, 0.0f);
	};
}

#endif // !GRAPHICS_RENDERER_H
