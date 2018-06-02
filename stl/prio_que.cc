 ///
 /// @file    prio_que.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-23 17:10:37
 ///
 
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using std::cout;
using std::endl;


template<typename T>
void print_que(T & t){
	while(!t.empty()){
		cout<<t.top()<<endl;
		t.pop();
	}
}

void  test(){
	std::priority_queue<int, std::vector<int>, std::greater<int> > pque;
	for(int n: {3, 4, 1, 7, 9, 10, 5, 6} ){
		pque.push(n);
	}
	print_que(pque);
}


int main(){
	test();
	return 0;
}
