 ///
 /// @file    for_each.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-25 10:31:14
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
using std::cout;
using std::endl;
using std::string;
using std::pair;
typedef std::vector<int> VI;
typedef std::map<int,string> MP;

void func(VI::value_type tp){
	cout<<tp<<" ";
}

void func2(MP::value_type m){
	cout<<"("<<m.first<<","<<m.second<<") ";
}
void test1(){
	int arr[]={1, 2, 3, 4, 5};
	VI ob(arr,arr+5);
	for_each(ob.begin(),ob.end(),func);	
	cout<<endl;
}

int main(){
	pair<int,string> arr[]={
		pair<int,string>(1,"he"),
		pair<int,string>(2,"llo"),
		pair<int,string>(3,"wor"),
		pair<int,string>(4,"ld")
	};
	MP ob(arr,arr+4);
	for_each(ob.begin(),ob.end(),func2);
	cout<<endl;
}
