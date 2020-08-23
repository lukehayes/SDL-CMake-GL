#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "Util/glm.h"

namespace Model {

	class Model
	{
	public:
		Model() : m_position(0,1,0){}
		Model(const glm::vec3 &position) : m_position(position) {}
		~Model() {}

		inline glm::mat4& GetMatrix()
		{
			return m_modelMatrix;
		}

        void Update(double delta)
        {
            m_modelMatrix = glm::translate(m_modelMatrix, m_position);
        }

		glm::vec3 m_position = glm::vec3(1.0f);

	private:
		glm::mat4 m_modelMatrix = glm::mat4(1.0f);

	};

}

#endif // !MODEL_MODEL_H
