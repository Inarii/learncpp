 ///
 /// @file    t2.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-13 23:50:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;


template <typename Tt,int num>
double func(Tt t){
	return t*num;
}

int main(){
	cout<<func<double,4>(3.2)<<endl;

}
