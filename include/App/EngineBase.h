#ifndef APP_ENGINE_BASE_H
#define APP_ENGINE_BASE_H

namespace App
{
	/*
	* All classes should inherit from this class
	*/
	class EngineBase
	{
	public:

		EngineBase();
		virtual ~EngineBase();

		virtual void Create() = 0;
		virtual void Destroy() = 0;
		virtual void Update(double dt) = 0;
		virtual void Render() = 0;

	private:

	};

	EngineBase::EngineBase()
	{
	}

	EngineBase::~EngineBase()
	{
	}
}

#endif // !APP_ENGINE_BASE_H
