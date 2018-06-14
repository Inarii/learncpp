 ///
 /// @file    textQuery.cc
 /// @author  Eric(zzw_zhiwei@qq.com)
 /// @date    2018-06-03 03:11:29
 ///
 
#include <ctype.h>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <fstream>
#include <sstream>
using std::string;
using std::map;
using std::vector;
using std::set;
using std::cout;
using std::endl;

class textQuery{
	public:
		textQuery(){}
		void readFile(const string fileName);
		void query(const string & word);
	private:
		vector<string> lines;
		map<string, set<int> > word2line;
		map<string, int> frequency;
};

void textQuery::readFile(const string fileName){
	std::ifstream ifs(fileName);
	int cnt = 1;
	for(string line; std::getline(ifs, line);cnt++){
		lines.push_back(line);
		for(size_t it = 0; it != line.size(); it++ ){
			if(!isalpha(line[it]))
				line[it]=' ';
		}
		string word;
		std::istringstream iss(line);
		while(iss >> word){
			++frequency[word]; //initalize to 0 ?
			word2line[word].insert(cnt);
		}
	}
}

void textQuery::query(const string & word){
	cout << word << " occurs " << frequency[word] << " times " <<endl; //frequency[word] > 1 ? "once":"times" << endl;
	set<int> & query_set = word2line[word];
	cout << " set size : " << query_set.size() <<endl;
	for(auto it = query_set.begin(); it != query_set.end(); it++){
		cout << "\t" << "(line " << *it << ") " << lines[*it -1] <<endl ; 
	}
}

int main(int argc, char * argv[]){
	if(argc != 2){
		cout<< " args error " <<endl;
		return 1;
	}
	textQuery *tq = new textQuery();
	tq->readFile(string(argv[1]));

	string query_word;
	while ( std::cin  >> query_word){
		tq->query(query_word);
	}		
	return 0;
}
