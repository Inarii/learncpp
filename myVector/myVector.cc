 ///
 /// @file    myVector.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-26 11:05:36
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

template<typename T>
class Vector{
	typedef T * iterator;
	public:
	Vector();
	~Vector();

	void push_back(const T & value);	
	void pop_back();
	T * begin(){return _start;}

	T * end(){return _finish;}
	
	int size()const;
	int capacity()const;
	private:
	void reallocate();

	static std::allocator<T> _alloc;

	T * _start;
	T * _finish;
	T * _end_of_range;

};

template< typename T>
std::allocator<T> Vector<T>::_alloc;

template<typename T>
Vector<T>::Vector()
:_start(0),
 _finish(0),
 _end_of_range(0)
{
	cout<<"myVector()"<<endl;
}

template< typename T>
Vector<T>::~Vector(){
 if(size()>0){
	while(_start != _finish){
		_alloc.destroy(--_finish);
	}

	_alloc.deallocate(_start,capacity());
 }
	cout<<"~Vector()"<<endl;
}

template< typename T>
int Vector<T>::size() const{
	return _finish - _start;
}

template< typename T>
int Vector<T>::capacity() const{
	return _end_of_range - _start;
}

template< typename T>
void Vector<T>::push_back(const T & value){
	if(size() == capacity())
		reallocate();
	_alloc.construct(_finish, value); //直接创建一个对象，而不是开辟空间
	++_finish;
}

template<typename T>
void Vector<T>::pop_back(){
	_alloc.destroy(--_finish);
}

template<typename T>
void Vector<T>::reallocate(){
	int oldCapacity= capacity();
	int newCapacity = oldCapacity==0 ? 1 : 2*oldCapacity;

	T * newStart = _alloc.allocate(newCapacity);	
	if(_start){
	//拷贝数据//
	std::uninitialized_copy(_start, _finish, newStart);

	//销毁原数据
	while(_start!= _finish){
		_alloc.destroy(--_finish);
	}

	//回收空间
	_alloc.deallocate(_start,oldCapacity);
	}
	_start = newStart;
	_finish= _start + oldCapacity;
	_end_of_range = _start + newCapacity;

}




class Point{
	private:
		int _x,_y;

	public:
		Point(int x, int y):_x(x),_y(y){
			cout<<"Point()"<<endl;
		}
		~Point(){
			cout<<"~Point()"<<endl;
		}
	friend std::ostream & operator<< (std::ostream & lhs, const Point & rhs);
};


std::ostream & operator<< (std::ostream & lhs, const Point & rhs){
	lhs<<"("<<rhs._x
		<<","<<rhs._y
		<<")"<<endl;
	return lhs;
}


template<typename T>
void displayCap(Vector<T> & val){
	cout<<"Vector capacity:"<<val.capacity()<<endl;
	cout<<"Vector size:"<<val.size()<<endl;
}


void test1(){
	Vector<int> v1;
	int round=7;
	for(int i=0;i!=round;i++){
		v1.push_back(i*2+1);
		displayCap(v1);
	}
	for(int i=0; i!=round;i++){
		v1.pop_back();
		displayCap(v1);
	}

}
void test2(){
	Vector<Point> v1;
	int round=7;
	cout<<"重新分配内存时，销毁原数据调用了多次析构函数"<<endl;
	for(int i=0;i!=round;i++){
		v1.push_back(Point(i,i*2+1));
		displayCap(v1);
		cout<<*(v1.end()-1)<<endl;
	}	
	cout<<endl;
	for(int i=0; i!=round;i++){
		v1.pop_back();
		displayCap(v1);
	}

}

int main(){
	test2();
}
