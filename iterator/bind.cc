 ///
 /// @file    bind.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-25 16:28:21
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <functional> 


using std::cout;
using std::endl;
using std::vector;
using std::bind;
//回调函数的几种形式
//
//

int func(int x, int y){
	cout<<"func()"<<endl;
	return x+y;
}

class Foo{

	public:
		int func2(int x,int y){
			cout<<"foo::func2()"<<endl;
			return x+y;
		}
};


void test1(){
	typedef int (*function) (int, int);	//函数指针式回调函数
	function f1=func; //注册回调函数
	int a=1,b=2;
	cout<<"a + b = "<<f1(a,b)<<endl; //执行回调函数
	auto f2 = bind(func,a,b);
	//对于不需要提前绑定的参数需要使用占位符
	auto f3 = bind(func,a,std::placeholders::_1);
	auto f4 = bind(func, std::placeholders::_1, std::placeholders::_2);
	cout<<f2()<<endl;
	cout<<f3(6)<<endl;
	cout<<f4(3,5)<<endl;
}


void test2(){
	Foo foo;
	//对于成员函数，必须加上取地址符号
	auto f1 = bind(&Foo::func2,foo,std::placeholders::_1, std::placeholders::_2);
	cout<<"1+2 = "<<f1(1,2)<<endl;
	//bind函数中提前绑定的参数都会复制，使用值传递
	auto f2 = bind(&Foo::func2,&foo,std::placeholders::_1,4);
	cout<<"3+4 = "<<f2(3)<<endl;
	//使用bind函数将成员函数包装成普通函数
}


 	void func3(int a1,int a2, int a3){
		cout<<a1<<" "<<a2<<" "<<a3<<endl;
	}
void test3(){
	using namespace std::placeholders;
	auto f1 = bind(func3,_2,4,_1); //最好还是一一对应
	f1(1,5); //第一个占位参数1，放在实参列表的最后一个，第_2个占位参数5，在实参列表的第一个
}

int main(){
	cout<<"where was the call-back function regisrated?"<<endl;
	test3();
}
