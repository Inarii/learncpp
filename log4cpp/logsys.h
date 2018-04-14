 ///
 /// @file    logsys.h
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-12 01:46:32
 ///

#ifndef __LOGSYS_H__
#define __LOGSYS_H__
#include<string>
#include<log4cpp/Category.hh>
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
class Mylogger{
public:
	static Mylogger * getInstance();
	static void destroy();
	
	void warn(const char * msg);
	void error(const char * msg);
	void debug(const char * msg);
	void info(const char * msg);
private:
	Mylogger();
	~Mylogger();
	static Mylogger * _pInstance;
	log4cpp::Category & _root;
};


inline string int2str(int number){
	std::ostringstream oss;
	oss<<number;
	return oss.str();
}

#define prefix(msg) string("[").append(__FILE__)\
	.append(":").append(__FUNCTION__)\
	.append(":").append(int2str(__LINE__))\
	.append(":").append(msg).c_str()

#define logwarn(msg) Mylogger::getInstance()->warn(prefix(msg))
#define logerror(msg) Mylogger::getInstance()->error(prefix(msg))
#define logdebug(msg) Mylogger::getInstance()->debug(prefix(msg))
#define loginfo(msg) Mylogger::getInstance()->info(prefix(msg))


#endif
