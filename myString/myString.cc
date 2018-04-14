 ///
 /// @file    myString.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-13 08:22:42
 ///

#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <limits>
using std::cout;
using std::endl;

class String{
public:
	String();
	String(const char *);
	String(const String &);
	String & operator=(const char *);
	String & operator=(const String &);

	
	String & operator+=(const char*);
	String & operator+=(const String &);

	friend bool operator==(const String &,const String &);
	friend bool operator!=(const String &,const String &);
	
	friend bool operator>(const String &,const String &);
	friend bool operator<(const String &,const String &);
	friend bool operator>=(const String &,const String &);
	friend bool operator<=(const String &,const String &);
	
	
	friend std::ostream & operator<<(std::ostream &os, const String & rhs);
	friend std::istream & operator>>(std::istream &is , String &rhs);
	

	~String();
	std::size_t size() const;
	const char * c_str() const;

private:
	char * _pstr;
};


String & String::operator+=(const char *str){
	String tmp(*this);
	this->_pstr = new char[this->size()+strlen(str)+1];
	sprintf(this->_pstr,"%s%s",tmp._pstr,str);
	return *this;
}


String & String::operator+=(const String & str){
	String tmp(*this);
	this->_pstr = new char [this->size()+ str.size() +1];
	sprintf(this->_pstr,"%s%s",tmp._pstr,str._pstr);
	return *this;
}


std::istream & operator>>(std::istream & is, String &rhs){
	std::istream::sentry sentry(is);
	if(!sentry){
		return is;
	}
	int next;
	while ((next=is.get())!=is.eof() && !std::isspace(next)){
		char  ch[2]={0};
		ch[0]= (char)next;
		String tm=ch;
		rhs+=tm;
	}
	return is;
}

bool operator>(const String & lhs,const String & rhs){
	if(strcmp(lhs.c_str(),rhs.c_str())>0){
		return true;
	}else{
		return false;
	}
}
bool operator<(const String & lhs,const String & rhs){
	if(strcmp(lhs.c_str(),rhs.c_str())<0){
		return true;
	}else{
		return false;
	}
}
bool operator>=(const String & lhs,const String & rhs){
	if(strcmp(lhs.c_str(),rhs.c_str())>=0){
		return true;
	}else{
		return false;
	}
}
bool operator<=(const String & lhs,const String & rhs){
	if(strcmp(lhs.c_str(),rhs.c_str())>0){
		return true;
	}else{
		return false;
	}
}
bool operator==(const String & lhs,const String & rhs){
	return (strcmp(lhs.c_str(),rhs.c_str()))?false:true;
}

bool operator!=(const String & lhs,const String & rhs ){
	return (strcmp(lhs.c_str(),rhs.c_str()))?true:false;
}

String & String::operator=(const String & str){
	delete _pstr;
	_pstr = new char[str.size()+1];
	strcpy(_pstr,str.c_str());
	return *this;
}

String & String::operator=(const char * str){
	delete _pstr;
	_pstr = new char[strlen(str)+1];
	strcpy(_pstr,str);
	return *this;
}

std::size_t String::size() const{
	return strlen(_pstr);
}

String::String()
:_pstr(new char[1])
{
	cout<<"String()"<<endl;
}

String::~String(){
	cout<<"~String()"<<endl;
	delete [] _pstr;
}


String::String(const char * str)
:_pstr(new char[strlen(str)+1])
{
	cout<<"String(const char *)"<<endl;
	strcpy(_pstr,str);
}

String::String(const String & str)
:_pstr(new char[str.size()+1])
{
	cout<<"String(const String &)"<<endl;
	strcpy(_pstr,str._pstr);	
}

const char * String::c_str() const{
	return _pstr;
}


String operator+(const String &lhs, const String &rhs){
	char * tmp = new char[lhs.size()+rhs.size()+1];
	sprintf(tmp,"%s%s",lhs.c_str(),rhs.c_str());
	String stmp(tmp);
	delete[] tmp;
	return stmp;
}

String operator+(const String &lhs,const char * rhs){
	char * tmp = new char[lhs.size()+strlen(rhs)+1];
	sprintf(tmp,"%s%s",lhs.c_str(),rhs);
	String stmp(tmp);
	delete[] tmp;
	return stmp;
}

String operator+(const char * lhs,const String &rhs){
	char * tmp = new char[rhs.size()+strlen(lhs)+1];
	sprintf(tmp,"%s%s",lhs,rhs.c_str());
	String stmp(tmp);
	delete[] tmp;
	return stmp;
}

std::ostream & operator<<(std::ostream &os, const String & rhs){
		os<<rhs.c_str();
		return os;
}

int test(){
	String s1="hello";
	String s2("world");
	String s3=s1+s2;
	cout<<s3<<endl;
	cout<<s1+"Heaven"<<endl;
	cout<<"Bye"+s2<<endl;
	s1="he";
	s2="he";
	cout<<"equal? "<<((s1==s2)?"Yes":"No")<<endl;
	
	return 0;
}


int test2(){
	String s1("hwool");
	String s2=" sad";
//	std::cin>>s1;
//	cout<<"s2="<<s2<<endl;
	s1+=s2;
	cout<<"s1="<<s1<<endl;
	return 0;
}


int main(){
	String s1;
	String s2;
	std::cin>>s1>>s2;
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	s1+=s2;
	
	cout<<"s1="<<s1<<endl;
		


}
