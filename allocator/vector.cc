 ///
 /// @file    vector.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-25 17:30:23
 ///
 
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
int main(){
	vector<int> arr;
	arr.push_back(1);
	arr.push_back(2);
	arr.push_back(2);
	cout<<"capacity:"<<arr.capacity()<<endl;
	arr.reserve(10);
	arr.push_back(2);
	cout<<"capacity:"<<arr.capacity()<<endl;
}
