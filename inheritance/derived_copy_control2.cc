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
			cout << "Base & operator = (const Base &)" << endl;
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
	Derived(const char * data, const char * data2)
	: Base(data)
	, _pData(new char[strlen(data2) + 1]())
	{
		cout << "Derived(const char *)" << endl;
		strcpy(_pData, data2);
	}

	Derived(const Derived & rhs )
	: _pData(new char[strlen(rhs._pData) + 1]())
	, Base(rhs)
	{
		cout << "Derived(const Derived &)" << endl;
		strcpy(_pData, rhs._pData);
	}
	Derived()
	{}
	~Derived(){
		cout << "~Derived()" << endl;
	}
	
	Derived & operator=(Derived & rhs){
		if(this != & rhs){
			Base::operator=(rhs);
			
			if(rhs._pData)
				delete [] _pData;
			_pData = new char[strlen(rhs._pData) + 1]();
			strcpy(_pData, rhs._pData);
		}
		return *this;
	}
	friend std::ostream  & operator<<(std::ostream & os ,const Derived & rhs);
	private:
		char * _pData;
};

std::ostream & operator<<(std::ostream & os ,const Derived & rhs)
{
//	os << rhs._pData; 友元关系不能继承
	os << (Base &) rhs << " , " << rhs._pData ; 
	return os;
}

int main(){
	Derived d1("Hello", "world");
	cout << "d1 = " << d1 << endl;
#if 0
	Derived d2 = d1; //执行的是复制构造函数，而不是赋值运算符重载
	cout << "d2 = " << d2 << endl; 
#endif
	Derived d3("guangdong", "shenzhen"); //执行赋值运算符重载，注意与d2的区别
	cout << "执行派生类的对象间的赋值操作" << endl;
	d3 = d1;
	cout << "d3 = " << d3 << endl;
	return 0;
}
