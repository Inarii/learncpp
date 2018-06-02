 ///
 /// @file    move.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-27 01:58:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;



class Point{
	public:
		Point(int x, int y):_x(x),_y(y){
			cout<<"Point()"<<endl;
		}
		~Point(){
			cout<<"~Point()"<<endl;
		}
		void setX(int nx){
			_x = nx;
		}
		friend std::ostream &  operator<<(std::ostream & os,const  Point & rhs);
	private:
		int _x;
		int _y;
};
std::ostream & operator<<(std::ostream & os, const Point & rhs){
	os << "(" << rhs._x
	   << "," << rhs._y
	   << ")";
	return os;
}

template<typename T>
class RAII{
	public:
		RAII(T * other):_p(other){
		 cout<<"RAII()"<<endl;
		}
		T * get(){
			return _p;
		}
		T * operator->(){
			return _p;	
		}
		T & operator*(){
			return *_p;
		}
		~RAII(){
			if (_p!=NULL) 
				delete _p;
		}
	private:
		T * _p;
};

int main(){
	RAII<Point> pPoint(new Point(1,2));
	pPoint->setX(10);
	cout<<*pPoint<<endl;
	return 0;
}

