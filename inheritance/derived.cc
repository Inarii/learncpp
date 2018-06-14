 ///
 /// @file    derived.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-13 21:58:49
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
//	public:A(){}
};

class B
:public A
{
	public:
	B(int x ){
		cout << "B(int) parameter = " << x << endl;
	}

};

int main(){
	B b(1);
	return 0;
}
