#pragma once
template<class MotionType>
class Singleton
{
private:
	Singleton() {}
	Singleton(const Singleton&) = delete;
	Singleton& operator=(const Singleton&) = delete;
	static MotionType* pInstance;
public:
	static MotionType* GetInstance();
};
template<class MotionType>
MotionType* Singleton<MotionType>::pInstance = nullptr;

template<class MotionType>
inline MotionType* Singleton<MotionType>::GetInstance()
{
	if (pInstance == nullptr)
		pInstance = new MotionType();
	return pInstance;
}
