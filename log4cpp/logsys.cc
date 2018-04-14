 ///
 /// @file    logsys.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-12 01:37:09
 ///
#include "logsys.h" 
#include <iostream>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/Priority.hh>

using std::cout;
using std::endl;

Mylogger * Mylogger::_pInstance=nullptr;
Mylogger * Mylogger::getInstance(){
	if(nullptr==_pInstance){
		_pInstance = new Mylogger;
	}
	return _pInstance;
}

void Mylogger::destroy(){
	if(_pInstance){
		delete _pInstance;
		_pInstance = nullptr;
	}
}

Mylogger:: Mylogger()
:_root(log4cpp::Category::getRoot() )
{
	cout<<"Mylogger() "<<endl;
	log4cpp::PatternLayout * pt1 = new log4cpp::PatternLayout;
	pt1->setConversionPattern("[%d] [%p] %m%n");
	
	log4cpp::PatternLayout * pt2 = new log4cpp::PatternLayout;
	pt2->setConversionPattern("[%d] [%p] %m%n");
	
	log4cpp::OstreamAppender  * OstrmApdr = new log4cpp::OstreamAppender ("ostreamAppender",&cout);
	OstrmApdr ->setLayout(pt1);

	log4cpp::FileAppender * fileApdr = new log4cpp :: FileAppender ("fileAppender","mylogdata.dat");
	fileApdr->setLayout(pt2);

	_root.addAppender(OstrmApdr);
	_root.addAppender(fileApdr);

	_root.setPriority(log4cpp::Priority::DEBUG);
}

Mylogger:: ~Mylogger()
{
	cout<<"~Mylogger()"<<endl;
	log4cpp::Category::shutdown();
}
	
void Mylogger::warn(const char *msg){
	_root.warn(msg);
}

void Mylogger::debug(const char *msg){
	_root.debug(msg);
}
void Mylogger::info(const char *msg){
	_root.info(msg);
}
void Mylogger::error(const char *msg){
	_root.error(msg);
}
