#include <iostream>
using std::cout;
using std::endl;


class Base
{
	public:
			virtual
					void display() const
						{	cout << "Base::display()" << endl;	}
	private:
				double _base;
};

class Child1 
: public Base
{
	public:
			virtual
					void display() const
						{	cout << "Child1::display()" << endl;}
	private:
				double _child1;
};


class Child2
: public Base
{
	public:
			void display() const
					{	cout << "Child2::display()" << endl;}
	private:
				double _child2;
};

//动态多态的特性：
////虚函数特性被激活的条件(实现原理)
////	前提条件 --> 对象创建完毕，才能使用虚函数
////1. 基类定义了虚函数
////2. 派生类重定义了基类的虚函数
////3. 基类的指针(引用)指向派生类对象
////4. 通过基类指针(引用)调用虚函数
//
void display(Base * pbase)  //Base * pbase = &child1/&child2
{//从编译时来看，应该只会调用Base类的display方法
 //从运行时来看，它会调用相应对象的display方法
 pbase->display();
}
void display(Base & base)
	{
	base.display();
	}

int main(void)
{
	Base base;
	Child1 child1;
	Child2 child2;
															//  本机     视频   平台有差异性	
	cout << "sizeof(Base) = " << sizeof(Base) << endl;			//12		16
	cout << "sizeof(Child1) = " << sizeof(Child1) << endl;		//20		24
	cout << "sizeof(Child2) = " << sizeof(Child2) << endl;		//20		24
	
	//通过对象名进行调用, 跟virtual关键字无关，表现的是隐藏
	base.display();
	child1.display();
	child2.display();
	cout << endl;	
	display(&base);
	display(&child1);
	display(&child2);
	cout << "基类的引用调用虚函数:" << endl;

	display(base);
	display(child1);
	display(child2);												
	return 0;
}

