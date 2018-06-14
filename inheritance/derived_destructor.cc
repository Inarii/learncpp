 ///
 /// @file    derived_destructor.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-04 00:01:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
	public:
		A(int x)
		: _ix(x)
		{
			cout << "A(int)" << endl;
		}
		~A(){
			cout << "~A()" << endl;
		}
	private:
		int _ix;
};

class B{
	public:
	B(){ cout << "B()" << endl; }
	~B(){ cout << "~B()" << endl; }
};

class C
:public A
{
	public:
	C(int x , int y)
	: _b()
	, A(x) 
	, _iy(y)
	{
		cout << "C(int ,int )" << endl;
	}

	~C(){ cout << "~C()" << endl; }
	private:
	int _iy;
	B _b;
};


int main(){
	C c(3,4);

}
