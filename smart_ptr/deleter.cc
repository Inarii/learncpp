 ///
 /// @file    deleter.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-02 17:53:17
 ///
 
#include <iostream>
#include <memory>
#include <string>
#include <cstdio> 

using std::cout;
using std::endl;
using std::string;
using std::unique_ptr;
using std::shared_ptr;

struct fcloser{
	void operator()(FILE *fp){
		if(fp)
		{
			fclose(fp);
			cout<< "file handle closed " << endl;
		}

	}

};

void  test0(){
	shared_ptr<FILE> sp(fopen("test.txt","w+"),fcloser());
	string s1("Hello World");
	fwrite(s1.c_str(),s1.size(),1,sp.get());
}


int main(){
	test0();
	return 0;
}

