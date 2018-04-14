 ///
 /// @file    funcObj.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-12 16:47:27
 ///

#include <iostream>
using std::cout;
using std::endl;

class FuncObj{	
public:
	int operator()(int x,int y){
		cnt++;
		return x+y;
	}

	int operator()(int x,int y,int z){
		cnt++;
		return x+y+z;
	}
	int get_cnt(){ return cnt;}
	int cnt=0;

};


int main(){
	FuncObj func1;
	cout<<"1+2="<<func1(1,2)<<endl;
	cout<<"1+2+3="<<func1(1,2,3)<<endl;
	cout<<"cnt="<<func1.get_cnt()<<endl;
}
