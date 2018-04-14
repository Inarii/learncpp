 //
 /// @file    variaTem.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-14 03:37:11
 ///
 
#include <iostream>
using std::cout;
using std::endl;


template <typename ...Args>
void func(Args ...args){
	cout<<"sizeof args ="<<sizeof...(args);

}





int main(){
	func(1,2,4,6);
	cout<<endl;

}

