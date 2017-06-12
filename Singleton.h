#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>

using namespace std;

class Singleton{
public:
	static Singleton* GetInstance();
	//Manully Destroy instance
	static void DestroyInstance(){
		if(m_pSingleton != nullptr){
			delete m_pSingleton;
			m_pSingleton = nullptr;
		}
	}
	void doSomething(){
		std::cout << "do Something..." << std::endl;
	}
private:
	Singleton(){}
	static Singleton *m_pSingleton;
	static mutex m_mutex;
	//auto-Destroy instance, GC
	class GC{
	public:
		~GC(){
			if(m_pSingleton != nullptr){
				std::cout << "Here Destroying the m_pSingleton..." << endl;
				delete m_pSingleton;
				m_pSingleton = nullptr;
			}
		}
		static GC gc;
	};
};

#endif