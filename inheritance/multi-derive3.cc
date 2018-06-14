 ///
 /// @file    multi-derive1.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-03 22:27:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A{
	public:
	void show(){
	cout << "A::_ix = " << _ix << endl; }
	void setX(int x){
		_ix = x;
	}
	private:
	int _ix;
};

class B
:virtual public A
{
	public: 
	void print(){
		cout << "B::print()" << endl; 
	}
};

class C
:virtual public A
{
	public: 
	void print(){
		cout << "C::print()" << endl; 
	}
};

class D:
public C,
public B{
	public:
	void display(){
		cout << "C::print()" << endl; 
	}
};

int main(){
	D d;
//	d.B::setX(10);
//	d.B::show();
//	d.C::setX(19);
//	d.C::show();
//
	d.setX(10);
	d.show();
}
