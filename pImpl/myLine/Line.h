 ///
 /// @file    Line.h
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-13 05:41:32
 ///


#ifndef __LINE_H__
#define __LINE_H__
#include <iostream>
using std::cout;
using std::endl;

class Line{
public:
	Line(int x1,int y1,int x2,int y2);
	~Line();
	void display() const;

private:
	class LineImpl;
	LineImpl * _pImpl;
};

#endif
