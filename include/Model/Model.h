#ifndef MODEL_MODEL_H
#define MODEL_MODEL_H

#include "Util/glm.h"

namespace Model {

	class Model
	{
	public:
		Model() : m_position(0,0,0){}
		Model(const glm::vec3 &position) : m_position(position) {}
		~Model() {}

		inline glm::mat4& GetMatrix()
		{
			return m_model_matrix;
		}

		glm::vec3 m_position = glm::vec3(1.0f);

	private:
		glm::mat4 m_model_matrix = glm::mat4(1.0f);

	};

}

#endif // !MODEL_MODEL_H
