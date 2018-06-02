 ///
 /// @file    romove.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-25 15:17:36
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::cout;
using std::endl;


 
//remove-erase惯用法 remove内部直接删除可能会漏删元素  
//迭代器会失效
//


void test(){
	std::vector<int> nums{1,2,3,4,5,6,7,8,9};
	nums[2]=nums[4]=nums[6]=99;
	nums.erase(std::remove(nums.begin(),nums.end(),99),nums.end());

	copy(nums.begin(),nums.end(),std::ostream_iterator<int>(cout, " ")); 
	
}

int main(){
	test();
	return 0;
}
