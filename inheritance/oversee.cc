 ///
 /// @file    Derivedd_destructor.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-04 00:01:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base{
	public:
	int func(int a){
		_ix = a ;
		return _ix;
	}
	protected:
	int _ix;
};

class Derived
: public Base
{
	public:
	void func(){
		_ix = 10;
		cout << " _ix = " << _ix << endl;
		cout << " Base::_ix = " << Base::_ix  << endl;
		cout << " Derived::_ix = " << Derived::_ix << endl; 
	}
	private:
	int _ix;

};


int main(){
	Derived  de;
//	cout << de.func(1) << endl;
	cout << de.Base::func(1) << endl;	
	de.func();
}
