#ifndef ARQUIVO_H
#define ARQUIVO_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Arquivo{
	private:
		FILE* fp;
		string _end;
		string _mode;
		bool _state;
	public:
		Arquivo(string e, string m);
		int size();
		void vocabulary(string end);
		FILE* getfp();
		string end();
		void open();
		void to_file(vector<string> &v);
		void to_vector(vector<string> &v);
		void to_map(map<string,set<string>*> &m);
		void ordenate();
		void print();
		void close();
};



#endif
