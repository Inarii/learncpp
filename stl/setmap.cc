 ///
 /// @file    set.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-23 23:53:35
 ///
 
#include <iostream>
#include <set>
#include <string>
#include <map>
using std::cout;
using std::endl;
using std::pair;
using std::string;
void test2(){
	pair<int,string> ps[2]={pair<int,string>(1,"a"),pair<int,string>(2,"b")};
	std::map<int,string> s1(ps,ps+2);
	std::map<int, string>::iterator it = s1.begin();
	pair <int, string> p1(3,"c");
	std::map<int, string>::iterator ret= s1.insert(it,p1);
		cout<<"insert at  "<<ret->first<<endl;
	for(auto & it :s1){
		cout<<"("<<it.first<<","<<it.second<<")"<<endl;

	}

}

void test(){
	pair<int,string> ps[2]={pair<int,string>(1,"a"),pair<int,string>(2,"b")};
	std::map<int,string> s1(ps,ps+2);
//	pair<int, string> p1(3,"c");
	auto it = s1.begin();

	pair<int, string> p1(2,"c");
	pair<std::map<int,string>::iterator, bool> ret= s1.insert(p1);
	if(ret.second){
		cout<<"insert correct "<<endl;
	}else{
		cout<<"insert failed"<<endl;
		cout<<"already has "<<(ret.first)->first<<endl;
	}
}


int main(){
	test2();
	return 0;
}
