 ///
 /// @file    bind_r.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-03 00:09:28
 ///
 
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;
using std::bind;
int func(int a, int b){
	cout << "func( int, int )" << endl;
	return a+b;
}


class Foo{
	public:
		int func2(int a, int b){
			cout << "func2(int, int )" << endl;
			return a+b;
		}
};


int test0(){
	typedef int (*function) (int ,int );
	function f1 = func;
	int a = 1 , b = 2;
	cout << " a + b = " << f1(a, b) << endl;
	auto f2 = bind(func,a,b+1);
	cout << " a + b + 1 = " << f2() << endl;
	auto f3 = bind(func,a,std::placeholders::_1);
	int x = 4;
	cout << " a + "<< x << " = " << f3(x) << endl; 
	return 0;
}

void test1(){
	Foo foo;
	auto f4 = bind(&Foo::func2, &foo,  std::placeholders::_1, std::placeholders::_2);
	int x = 3, y = 4;
	printf("%d + %d = %d\n", x, y, f4(x,y));
	auto  f3 = [](int x, int y)->int{  // bind 注册回调函数可以用lambda表达式代替，而不是注册lambda表达式
			cout << "lambda funct ( "<< x << "," << y << " ) return " ;
			return x + y;
	};
	cout << f3(x+1,y+2) <<endl;
}

int main(){
	test1();
	return 0;
}
