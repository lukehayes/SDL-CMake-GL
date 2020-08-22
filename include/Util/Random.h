#ifndef UTIL_RANDOM_H
#define UTIL_RANDOM_H

#include <random>

/**
 * Random value generator helper class
 */
namespace Util {

	class Random
	{
	public:
		Random() {}
		~Random() {}
	
		/**
		 * Generate a random float from 0.0 to 10.0 by default
		 * 
		 *  @param float from The randomly generated from value
		 *  @param float to The randomly generated to value
		 *  
		 *  @return float The randomly generated number
		 */
		static float GetFloat(float from = 0, float to = 10.0)
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_real_distribution<> dist(from, to);

			return dist(gen);
		}

		/**
		 * Generate a random integer from 0 to 10 by default
		 * 
		 *  @param int from The randomly generated from value
		 *  @param int to The randomly generated to value
		 *  
		 *  @return int The randomly generated number
		 */
		static int GetInt(int from = 0, int to = 10.0)
		{
			std::random_device rd;
			std::mt19937 gen(rd());
			std::uniform_int_distribution<> dist(from, to);

			return dist(gen);
		}

	};


}


#endif // !UTIL_RANDOM_H
