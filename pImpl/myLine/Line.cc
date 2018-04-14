 ///
 /// @file    Line.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-13 05:45:25
 ///

#include "Line.h"
#include <iostream>
using std::cout;
using std::endl;

class Line::LineImpl{
	class Point{
	public:
		Point(int ix,int iy)
		:_ix(ix),_iy(iy)
		{
			cout<<"Point(int , int)"<<endl;
		}

		~Point(){
			cout<<"~Point()"<<endl;
		}
		void display() const{
			cout<<"("<<_ix
				<<","<<_iy
				<<")"<<endl;
		}
	private:
		int _ix;
		int _iy;
	};

public:
	LineImpl(int x1,int y1, int x2, int y2)
	:_p1(x1,y1),_p2(x2,y2)
	{
		cout<<"LineImpl(int,int,int,int)"<<endl;
	}
	~LineImpl(){
			cout<<"~LineImpl()"<<endl;
	}

	void display() const{
		cout<<"Line";
		_p1.display();
		cout<<"--->";
		_p2.display();
		cout<<endl;
	}
private:
	Point _p1;
	Point _p2;
};

Line::Line(int x1,int y1,int x2, int y2)
:_pImpl(new LineImpl(x1,y1,x2,y2))
{
	cout<<"Line(int, int, int, int)"<<endl;
}

Line::~Line(){
	cout<<"~Line()"<<endl;
	if(_pImpl){
		delete _pImpl;
	}
}

void Line::display()const{
	_pImpl->display();
}
