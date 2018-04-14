 ///
 /// @file    t3.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-14 04:50:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;

template<class T1,int num1>
class Stack{
public:
	int returnNum();
private:
	T1 arr[num1];
};


template<class T,int num>
int Stack<T,num>::returnNum(){
	return num;	
}

template<template<class typeClass,int n>class foo,class t2,int n>
void disp(){
	foo<t2,n> ob1;
	cout<<ob1.returnNum()<<endl;
}

int main(){
	disp<Stack,int,8>();
	cout<<endl;

}
