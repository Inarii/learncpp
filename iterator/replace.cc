 ///
 /// @file    replace.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-25 13:14:48
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::vector;
using std::cout;
using std::endl;

void test(){
	vector<int> nums{1,2,3,4,5,6,7};
	std::less<int> lt;

	//std::replace_if(nums.begin(),nums.end(),bind1st(lt,3),7);
	std::replace_if(nums.begin(),nums.end(),bind2nd(lt,3),7);
	
	std::ostream_iterator<int> osi(cout,"-");
	copy(nums.begin(),nums.end(),osi);
}

int main(){
	test();
	return 0;
}
