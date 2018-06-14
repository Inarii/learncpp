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
	void print(){
	cout << "A::print()" << endl; }
	void setX(int x){
		_ix = x;
	}
	private:
	int _ix;
};

class B{
	public: 
	void print(){
		cout << "B::print()" << endl; 
	}
};

class C:
public A,
public B{
	public:
	void print(){
		cout << "C::print()" << endl; 
	}
};

int main(){
	C c;
	c.print();
}
