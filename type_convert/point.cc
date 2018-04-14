 ///
 /// @file    point.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-12 10:35:22
 ///
 

#include <iostream>
#include <cmath>
using std::cout;
using std::endl;

class Point{
public:
	Point(double x=0,double y=0)
	:_ix(x),_iy(y)
	{
		cout<<"point (double,double)"<<endl;
	}

	void print() const {
		cout<<"("<<_ix
			<<","<<_iy
			<<")";
	}

	operator int(){
		return _ix;
	}


	friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
//	friend double dis(const Point & lhs,const Point &rhs);
	~Point(){
		cout <<"~Point()"<<endl;
	}
private:
	double _ix;
	double _iy;
};

	std::ostream & operator<<(std::ostream & os,const Point & rhs){
			os<<"("<<rhs._ix
				<<","<<rhs._iy
				<<")"<<endl;
			return os;
	}

#if 0
double dis(const Point  &lhs, const Point &rhs){
	return sqrt((lhs._ix-rhs._ix)*(lhs._ix-rhs._ix) +
				(lhs._iy-rhs._iy)*(lhs._iy-rhs._iy)		
			);
}
#endif
int test(){
	Point p1(1,0);
	Point p2(0,1);
	//cout<<dis(p1,p2)<<endl;
	return 0;
}


int main(){
	Point p1(1,2);
	cout<<"p1="<<p1<<endl;
	int a=p1;
	cout<<"convert as:"<<a<<endl;
}
