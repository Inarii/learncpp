 ///
 /// @file    unique_ptr.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-02 13:15:36
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::unique_ptr;

///不能进行复制

unique_ptr<int> getValue(){
	unique_ptr<int> up(new int(5));
	return up;
}


int main(){
	unique_ptr<int> up(new int(10));
	std::vector<unique_ptr<int> > vp;
	vp.push_back(std::move(up));  //up是左值，push_back会进行复制，但是unique_ptr无法复制，需要用move将其转为右值
	cout<<*vp.front()<<endl;

//unique_ptr具有移动语义, 定义了移动函数
	unique_ptr<int> up2 = getValue(); // getValue() 的返回值是一个右值
	cout<< " *up2 = " << *up2 <<endl;

}

