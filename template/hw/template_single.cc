 ///
 /// @file    template_single.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-14 09:32:28
 ///

#include <pthread.h>
#include <cstdio>
#include <iostream>
using std::cout;
using std::endl;


// normal Singleton
//
//
//
#if 0
class Singleton{
public:
	class autoRelease{
		public:	
			autoRelease(){ cout<<"autoRelease()"<<endl;}
			~autoRelease(){
				cout<<"~autoRelease()"<<endl;
				delete _pInstance;	
			}
	};
	static Singleton * getInstance(){
		if(nullptr==_pInstance ){
			_pInstance = new Singleton;
		}
		return _pInstance;
	}
private:
	static Singleton * _pInstance;
	static autoRelease _autoR; 
	Singleton(){ cout<<"Singleton()"<<endl;}
	~Singleton(){ 
		cout<<"~Singleton()"<<endl;}
};

Singleton*  Singleton::_pInstance;
Singleton::autoRelease Singleton::_autoR;
#endif

#if 0
class Singleton{
	public:
		static Singleton * getInstance(){	
		/*
			if(nullptr==_pInstance)
				_pInstance = new Singleton;
		*/
			::pthread_once(&_once,init);	
			return _pInstance;
		}
	private:	
		static void init(){
			_pInstance =  new Singleton;
			::atexit(destroy);
		}
		static void destroy(){
			if(_pInstance)
				delete _pInstance;
		}
	private:
		Singleton(){cout<<"Singleton()"<<endl;}
		~Singleton(){cout<<"~Singleton()"<<endl;}
		static Singleton * _pInstance;
		static pthread_once_t _once;
};

Singleton * Singleton::_pInstance=nullptr;
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;

#endif

template<class ele>
class Singleton{
	public:
	static ele * getInstance(){
		pthread_once(&_once,init);
		return _pInstance;
	}
	private:
	static void init(){
		_pInstance = new ele;
		::atexit(destroy);
	}

	static void destroy(){
		if(_pInstance)
			delete _pInstance;
	}

	private:
	static ele * _pInstance;
	static pthread_once_t _once;
	Singleton(){}
	~Singleton(){}
};

template<class ele>
ele* Singleton<ele>::_pInstance = nullptr;
template<class ele>
pthread_once_t Singleton<ele>::_once = PTHREAD_ONCE_INIT;


int main(){
	int * p1 =Singleton<int>::getInstance();
	int * p3 =Singleton<int>::getInstance();
	double * p2 =Singleton<double>::getInstance();
	double * p4 =Singleton<double>::getInstance();
	printf("p1=%p\n",p1);
	printf("p3=%p\n",p3);
	printf("p2=%p\n",p2);
	printf("p4=%p\n",p4);



}
