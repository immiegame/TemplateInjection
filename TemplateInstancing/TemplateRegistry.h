#pragma once
#include <vector>
#include "RandomClass.h"


class ClassType 
{
public:
	virtual void* getObj()const = 0;
};

template<typename T>
class ClassTypeImpl : ClassType 
{
public:
	virtual void* getObj()const { return new T; }
	static ClassType* getNewInject() { return (ClassType*)new ClassTypeImpl<T>; }
};


template <class T>
class TemplateRegistry {
public:
	std::vector<ClassType*> RegisteredClasses;
	T* getNew(int index) const { return (T*)RegisteredClasses[index]->getObj(); }

	void InjectClass(ClassType* Class);
	void RegisterClasses();
};

template<class T>
inline void TemplateRegistry<T>::InjectClass(ClassType* Class)
{
	RegisteredClasses.push_back((ClassType*)Class);
}

template<class T>
inline void TemplateRegistry<T>::RegisterClasses()
{
	InjectClass(ClassTypeImpl<RandomClass>::getNewInject());
	InjectClass(ClassTypeImpl<RandomSubclass>::getNewInject());
}
