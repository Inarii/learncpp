 ///
 /// @file    reverse_iterator.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-25 12:59:08
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::copy;

void test(){
	vector<int> nums{1,2,3,4,5,6,7};
	//std::reverse_iterator<int> cit 是错误的用法	
	for(vector<int>::const_reverse_iterator cit=nums.rbegin();cit != nums.rend(); ++cit){
		cout<< *cit<<" ";
	}
	cout<<endl;
}

int main(){
	test();
	return 0;

}
