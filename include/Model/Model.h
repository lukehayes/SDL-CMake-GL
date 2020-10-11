#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "Util/glm.h"

namespace Model {

	class Model
	{
	public:
		Model() : m_position(0,0,-5.0), m_vertexCount(6) {}
		Model(const glm::vec3 &position) : m_position(position) {}
		~Model() {}

        void SetPosition(glm::vec3 position)
        {
			glm::translate(this->m_model_matrix, position);
        }

		inline glm::mat4 GetMatrix()
		{
			//return glm::translate(m_model_matrix, m_position);
			return m_model_matrix;
		}

		glm::vec3 m_position;
		int m_vertexCount = 6;

	private:
		glm::mat4 m_model_matrix = glm::mat4(1.0f);

	};

}

#endif // !MODEL_MODEL_H
