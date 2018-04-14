 //
 /// @file    t1.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-13 23:07:23
 ///
 
#include <iostream>
#include <string>
using std::cout;
using std::endl;

template <typename T>
T add(const  T &a ,const T &b){
	return a+b;
}

int main(){
	int a=3,b=5;
	double d1=1.2,d2=3.5;
	cout<<"a+b="<<add(a,b)<<endl;
	cout<<"d1+d2="<<add(d1,d2)<<endl;
	std::string s1("hello");
	std::string s2("world");
	cout<<"string add:"<<add(s1,s2)<<endl;
	return 0;
}
