 ///
 /// @file    template_queue.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-04-14 08:12:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;


template<class elmtType,int qSize>
class myQueue{
public:
	myQueue(){
		_qfront = 0;
		_qrear = 0;
		_qSize=qSize;
		cout<<"myQueue()"<<endl;
	}
	~myQueue(){
		cout<<"~myQueue()"<<endl;
	};
	
	void push(elmtType);
	void pop();
	elmtType front();
	elmtType rear();
	int getLength();
	elmtType full();
	int getSize(){return _qSize;}
private:
	int _qfront;
	int _qrear;
	int _qSize;
	elmtType  que[qSize];
};

template<class eTp,int qSz>
void myQueue<eTp,qSz>::push(eTp ele){
	que[_qrear]=ele;
	_qrear=(_qrear + 1)%_qSize;

}

template<class eTp,int qSz>
void myQueue<eTp,qSz>::pop(){
	_qfront=(_qfront+1)%_qSize;
}

template<class eTp, int qSz>
int myQueue<eTp,qSz>::getLength(){
#if 0
	cout<<"front="<<_qfront<<" rear= "<<_qrear<<"qsize="<<_qSize<<endl;
#endif
	return (_qrear+_qSize-_qfront)%_qSize;
}

template<class eTp,int qSz>
eTp myQueue<eTp, qSz>::front(){
	return _qfront;
}

template<class eTp,int qSz>
eTp myQueue<eTp, qSz>::rear(){
	return (_qrear-1+_qSize)%_qSize;
}

template<class eTp,int qSz>
eTp myQueue<eTp, qSz>::full(){
	return getLength()==(_qSize-1);
}
int main(){
	myQueue<int,10> que;
	myQueue<char,10> que2;
	int k=1;
	for(int i=0;i!=4;i++){
		que.push(k);
		que2.push(i+'a');
		k*=2;
	}
	for(int i=0;i!=4;i++){
		//cout<<que.getLength()<<' ';
		cout<<que.front()<<' ';
	}
	for(int i=0;i!=4;i++){
		//cout<<que.getLength()<<' ';
		cout<<que2.front()<<' ';
	}
	cout<<endl;
}
