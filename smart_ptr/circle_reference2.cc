 ///
 /// @file    circle_reference.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-02 15:07:10
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;
class Child;

class Parent{
	public:
	Parent(){cout<<"Parent()"<<endl; }
	~Parent(){ cout<< "~Parent()" <<endl; }
	shared_ptr<Child> _pChild;
};

class Child{
	public:
	Child(){cout<<"Child()"<<endl; }
	~Child(){ cout<< "~Child()" <<endl; }
	weak_ptr<Parent> _pParent;
};

int main(){
	shared_ptr<Parent> pParent(new Parent());
	shared_ptr<Child> pChild(new Child());
	cout<<"pParent count: " <<  pParent.use_count() << endl; 
	cout << "pChild count: " << pChild.use_count() << endl;

	//shared_ptr的循环引用会导致内存泄漏
		//解决方案是将其中一个指针设置为weak_ptr
		//	//weak_ptr做赋值操作的时候，不会改变引用计数的值
	pParent->_pChild = pChild;
	pChild->_pParent = pParent;
	cout << "after reference:" << endl;
	cout<<"pParent count: " <<  pParent.use_count() << endl; 
	cout << "pChild count: " << pChild.use_count() << endl;
	//程序结束时位于栈上的智能指针释放引用计数，
	//但类型内部的引用使计数不为0，堆空间上的对象不释放导致内存泄漏
	return 0;
}
