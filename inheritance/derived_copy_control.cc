#include <iostream>
#include <cstring>
using std::cout;
using std::endl;

class Base{
	public:
		Base(){ cout << "Base()" << endl; }
		
		Base(const char * pstr)
		: _pData(new char[strlen(pstr) + 1]())
		{
			cout << "Base(const char *)" << endl;
			strcpy(_pData, pstr);
		}

		Base(const Base & rhs)
		: _pData(new char[strlen(rhs._pData) + 1]())
		{
			cout << "Base(const Base &)" << endl;
			strcpy(_pData, rhs._pData);
		}

		Base & operator=(const Base & rhs)
		{
			cout << "operator = " << endl;
			if(this != &rhs){
				if(_pData)
					delete [] _pData;
				 _pData = new char[strlen(rhs._pData) + 1]();
				strcpy(_pData, rhs._pData);
			}
			return *this;
		}

		friend std::ostream & operator<<(std::ostream & os,const Base & rhs);

		~Base(){
			if( _pData != NULL){
				delete [] _pData;
			}
			cout << "~Base()" << endl; 
		}
	private:
		char *_pData=NULL;
};
std::ostream & operator<<(std::ostream & os,const Base & rhs)
{
	os << rhs._pData;
	return os;
}

class Derived
: public Base
{
	public:
	Derived(const char * data)
	: Base(data)
	{
		cout << "Derived(const char *)" << endl;
	}
	Derived()
	{}
	~Derived(){
		cout << "~Derived()" << endl;
	}

	friend std::ostream  & operator<<(std::ostream & os ,const Derived & rhs);
};

std::ostream & operator<<(std::ostream & os ,const Derived & rhs)
{
//	os << rhs._pData; 友元关系不能继承
	os << (Base &) rhs; 
	return os;
}

int main(){
	Derived d1("Hello");
	cout << "d1 = " << d1 << endl;

	Derived d2 = d1; //执行的是复制构造函数，而不是赋值运算符重载
	cout << "d2 = " << d2 << endl; 
	
	Derived d3; //执行赋值运算符重载，注意与d2的区别
	d3 = d1;
	cout << "d3 = " << d3 << endl;

	return 0;
}
