 ///
 /// @file    weak_ptr.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-02 17:37:29
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

struct Foo{
	void display() const { cout << "Foo::display()" << endl; }
};
//weak_ptr不能单独使用,必须结合shared_ptr才能使用
int main(){
	weak_ptr<Foo> wp;
	{
		shared_ptr<Foo> sp(new Foo());
		cout << "sp's use count: " << sp.use_count() << endl;

		wp = sp;
		cout << "wp's use count: " << wp.use_count() << endl;
	//weak_ptr不能直接访问资源
	//cout << "*wp = " << *wp << endl;
	
		shared_ptr<Foo> sp2 = wp.lock(); //对weak_ptr进行提升, 提升为shared_ptr才能访问资源
		if(sp2){
			cout << "promoted successfully" << endl;
			sp2->display();
		}else{
			cout << "promoted failingly" << endl;
		}
	}
	
	cout << endl << "退出语句块之后，Foo对象的生命周期已经结束" << endl;
	cout << "尽管weak_ptr对象还存在,但它知道它所托管的对象是否存活" << endl;

	shared_ptr<Foo> sp3 = wp.lock();
	if(sp3){
		cout << "promoted successfully" << endl;
		sp3->display();
	}else{
		cout << "promoted failingly" << endl;
	}
	return 0;
}
