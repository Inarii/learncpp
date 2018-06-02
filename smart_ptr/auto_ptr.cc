 ///
 /// @file    auto_ptr.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-02 12:56:57
 ///
 
#include <iostream>
#include <memory>

using std::cout;
using std::endl;
using std::auto_ptr;

int main(){
	int * p  = new int(10);
	auto_ptr<int> ap(p);
	cout<<"*p = "<< *p << " *ap = " << *ap<<endl;
	cout<<" p= " << p << " ap = " << ap.get() <<endl;
	return 0;
}
