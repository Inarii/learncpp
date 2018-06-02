 ///
 /// @file    istream_iterator.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-25 12:32:54
 ///
 
#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;
using std::copy;
using std::cin;

void test(){
	vector<int> nums;
	std::istream_iterator<int> isi(cin);
	cout<< "> input completly:"<<endl;

	copy(isi, std::istream_iterator<int>(), std::back_inserter(nums));

	std::ostream_iterator<int> osi(cout, "-");
	copy(nums.begin(),nums.end(),osi);
	cout<<endl;

	cout<<endl<<"output of nums:"<<endl;
	for(auto & it :nums){
		cout<<it<<" ";
	}
	cout<<endl;
}
int main(){
	test();
	return 0;
}

