 ///
 /// @file    complex.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-12 16:14:04
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Complex{
public:
	Complex(double real=0,double imag=0)
	:_real(real),_imag(imag)
	{
		cout<<"Complex(double,double)"<<endl;
	}
	~Complex(){
		cout<<"~Complex()"<<endl;
	}
	void display() const{
		if(_real==0){
			cout<<_imag<<"i";
		}else{
			cout<<_real;
			if(_imag==0){
				cout<<endl;
			}else if(_imag>0){
				cout<<"+"<<_imag<<"i"<<endl;
			}else{
				cout<<_imag<<"i"<<endl;
			}
		}
	}
	
	double getReal()const{return _real;}
	double getImag()const{return _imag;}
	friend Complex operator+(const Complex & lhs, const Complex & rhs );
	Complex operator+=(const Complex & rhs);
private:
	double _real;
	double _imag;
};

Complex operator+(const Complex & lhs, const Complex & rhs){
	return Complex(lhs._real+rhs._real,
					lhs._imag+rhs._imag);
}

Complex Complex::operator+=(const Complex & rhs){
	_real+=rhs._real;
	_imag+=rhs._imag;
	return *this;
}


int main(){
	Complex c1=Complex(1,-2);
	Complex c2=Complex(3,4);
	c1.display();
	c2.display();
	Complex c3=c1+c2;
	c3.display();
	Complex c4=Complex(0,-2);
	Complex c5=Complex(-3,0);
	cout<<"c4=";
	c4.display();
	cout<<endl<<"c5=";
	c5.display();
	c3=c4+c5;
	c3.display();
	c3+=c3;
	c3.display();
}
