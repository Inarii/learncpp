 ///
 /// @file    test.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-14 10:31:56
 ///
 
#include <iostream>
#include <cstdio>
using std::cout;
using std::endl;

class single{
	public:
	static single * getins(){
	if(nullptr==_pins){
		_pins = new single;
	}
	return _pins;
	}
	private:
	static single * _pins;
	single(){
		cout<<"single()"<<endl;
	}
	~single(){
		cout<<"~single()"<<endl;
	}
};

single * single::_pins=nullptr;


int main(){
	single * p1= single::getins();
	single * p2= single::getins();
	single * p3= single::getins();
	printf("p1= %p\n",p1);
	printf("p2 %p\n",p2);
	printf("p3= %p\n",p3);
}
