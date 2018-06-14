 ///
 /// @file    HeapSort_template.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-03 06:11:11
 ///
 
#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

template<typename T , typename Compare = std::less<T> >
class HeapSort{
	public:
		HeapSort(vector <T> & array)
		:_arr(array)
		{}
		void heapAdjust(int parent , size_t range);
		void sort();
	private:
		vector<T> & _arr;
};


template <typename T , typename Compare>
void HeapSort<T, Compare>::heapAdjust(int parent, size_t range){
	T tmp = _arr[parent];
	Compare comp;
	int child = parent * 2 + 1;
	while(child < range){
		if( (child + 1) < range && comp(_arr[child] , _arr[child + 1]))
			++child;
		if( comp(tmp, _arr[child])){
			_arr[parent] = _arr[child];
			parent = child;
			child = parent * 2 + 1;
		}else{
			break;	
		}

	}
	_arr[parent] = tmp;
}

template <typename  T , typename Compare>
void HeapSort<T, Compare>::sort(){
	//build the initial heap
	for(int itx = _arr.size()/2 -1; itx >= 0 ; --itx ){
		heapAdjust(itx, _arr.size() );
	}
	
	for(int itx = _arr.size()-1; itx >= 0; --itx ){
		std::swap(_arr[0],_arr[itx]);
		heapAdjust(0, itx);
	}
}

int main(){
	vector<int> vi{6, 8, 3, 2, 5, 4, 1, 9, 7};
	HeapSort<int> hp(vi);
	hp.sort();
	for(auto it = vi.begin(); it != vi.end() ; it++){
		cout<<*it<<" ";
	}
	cout<<endl;

}
