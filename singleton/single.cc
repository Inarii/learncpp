 ///
 /// @file    single.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-11 22:56:04
 ///
 
#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;

class singleton{
public:
	static singleton * getInstance(){
		if(_instance==NULL){
			_instance = new singleton;
		}
		return _instance;
		
	}
private:
	static singleton * _instance;
	singleton(){}
};


singleton *	singleton::_instance=NULL;



int main(){
	singleton * p1 = singleton::getInstance();
	singleton * p2 = singleton::getInstance();
	singleton * p3 = singleton::getInstance();
	printf("p1=%p\n",p1);
	printf("p2=%p\n",p2);
	printf("p3=%p\n",p3);
}
