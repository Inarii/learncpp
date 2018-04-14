 ///
 /// @file    single2.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-11 23:28:20
 ///
#include <cstdio> 
#include <iostream>
using std::cout;
using std::endl;

class Singleton{
	public:
	static Singleton * getInstance(){
		if(_pInstance==NULL)
			_pInstance = new Singleton ;
		return _pInstance;
	}
	private:
	Singleton(){}
	static Singleton * _pInstance;
};

Singleton *  Singleton::_pInstance=NULL;

int main(){
	Singleton * p1=Singleton::getInstance();
	Singleton * p2=Singleton::getInstance();
	printf("p1=%p\n",p1);
	printf("p2=%p\n",p2);
}
