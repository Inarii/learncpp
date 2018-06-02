 ///
 /// @file    insert_iterator.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-25 12:10:46
 ///
 
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <list>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::front_insert_iterator;
using std::back_insert_iterator;
using std::insert_iterator;
using std::copy;


template <typename Container>
void displayContainer(const Container & c){
	typename Container::const_iterator cit;
	for(cit=c.begin();cit != c.end(); ++cit){
		cout<< *cit << " ";
	}
	cout<<endl;
}

void test(){
	vector<int> nums{2,3,4,5};
	list<int> listInt;

#if 1
	copy(nums.begin(),nums.end(),
		front_insert_iterator<list<int>  >(listInt));
	displayContainer(listInt);
#endif
	copy(nums.begin(),nums.end(),
		back_insert_iterator<list<int> >(listInt));
	displayContainer(listInt);

	copy(nums.begin(),nums.end(),
		insert_iterator<list<int> >(listInt, ++listInt.begin()));			
	displayContainer(listInt);
}

int main(){
	test();
	return 0;
}
