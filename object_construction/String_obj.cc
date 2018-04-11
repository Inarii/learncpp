 ///
 /// @file    String_obj.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-04-11 15:47:05
 ///
 
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

class String{
	public :
		void print(){
			cout<<"content = "<< _pstr<<endl;
		}
		String()
		:_pstr(new char[1])
		{
			cout<<"String()"<<endl;
		}
		String(const char *pstr)
		:_pstr(new char[strlen(pstr)+1])
		{
			cout<<"String(const char *)"<<endl;
			strcpy(_pstr,pstr);
		}
		String(const String & );

		String & operator = (const String &sp );
		~String(){
			delete[] _pstr;
			cout<<"~String()"<<endl;
		}
	private:
		char * _pstr;
};


String & String::operator=(const String &op){
	_pstr = new char[strlen(op._pstr)+1];
	strcpy(_pstr,op._pstr);
	cout<<"String & String(const String &)"<<endl;
	return (*this);
}

String :: String(const String &sp)
:_pstr(new char[strlen(sp._pstr)+1])
{
	cout<<"String(const String &)"<<endl;
	strcpy(_pstr,sp._pstr);
}
int main(){
	String sa;
	String sb("hello world");
	sb.print();
	String sc = sb;
	sc.print();
	
	return 0;
}

