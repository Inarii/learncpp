 /// @file    AutoReleaseSingleton.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-13 07:39:59
#include <iostream>
using std::cout;
using std::endl;
class Singleton{

	class AutoRelease{
	public:
		AutoRelease(){ cout << "AutoRelease()" << endl;}
		~AutoRelease(){
			if(_pinstance){
				delete _pinstance;
				cout<< "~AutoRelease()" <<endl;
			}
		}
	};
public:
	static Singleton * getInstance(){
		if(nullptr==_pinstance){
			_pinstance = new Singleton();
		}
		return _pinstance;
	}
	void display() const {
		cout<<"Damn Single"<<endl;
	}
private:
	Singleton(){
		cout<<"Singleton()"<<endl;
	}
	~Singleton(){
		cout<<"~Singleton()"<<endl;
	}
	static Singleton * _pinstance;
	static AutoRelease _auto;
};

Singleton * Singleton::_pinstance = getInstance();
Singleton::AutoRelease Singleton::_auto;
int main(){
	Singleton *p1=Singleton::getInstance();
	Singleton *p2=Singleton::getInstance();
	cout<<"p1="<<p1<<endl;
	cout<<"p2="<<p2<<endl;
}
