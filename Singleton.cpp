#include "Singleton.h"


// This is lazy
//efficient, multi-thread insecure
/*
Singleton* Singleton::m_pSingleton = nullptr;
mutex Singleton::m_mutex;

Singleton* Singleton::GetInstance(){
	std::lock_guard<std::mutex> lock(m_mutex);
	if(m_pSingleton == nullptr)
		m_pSingleton = new Singleton();
	return m_pSingleton;
}*/
//End lazy


//this is hungry
//inefficient, yet multi-thread secure
Singleton* Singleton::m_pSingleton = new Singleton();
Singleton* Singleton::GetInstance(){
	return m_pSingleton;
}
//end hungry

//Auto-Destroy, declair GC
Singleton::GC Singleton::GC::gc;

int main(){
	//using Singleton
	Singleton::GetInstance()->doSomething();

	//Manully Destroy
	Singleton::GetInstance()->DestroyInstance();
	return 0;
}