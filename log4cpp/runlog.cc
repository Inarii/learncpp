 ///
 /// @file    runlog.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-12 03:01:26
 ///

#include "logsys.h"
#include <iostream>

int main(){
	logerror("error msg");
	Mylogger::destroy();
	loginfo("info msg");
	Mylogger::destroy();
	return 0;
}

using std::cout;
using std::endl;
