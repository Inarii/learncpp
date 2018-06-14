 ///
 /// @file    virtual_func.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-14 04:40:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;


class Base{
	public:
	virtual void  display() 
	const { cout << "Base::display()" << endl; }
	private:
	double _data;
};

class Child1
:public Base
{
	public:
	void display()
	const { cout << "Child1::display()" << endl; }
	private:
	double _data;
};


class Child2
:public Base
{
	public:
	void display()
	const { cout << "Child2::display()" << endl; }
	private:
	double _data;
};

void display(Base * p){
	p->display();
}

void display(Base & p){
	p.display();
}

int main(){
	Base b;
	Child1 c1;
	Child2 c2;
	
	cout << "sizeof(Base): " <<  sizeof(Base) << endl;
	cout << "sizeof(Child1): " << sizeof(Child1) << endl;
	cout << "sizeof(Child2): " << sizeof(Child2) << endl;

	display(&b);
	display(&c1);
	display(&c2);
	
	display(b);
	display(c1);
	display(c2);
	return 0;
}
