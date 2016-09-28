#ifndef __PARER__INI_H
#define __PARER__INI_H

#include<iostream>
#include <fstream>
#include<map>
#include<vector>
#include<string>
#include<list>
#include <string.h>
using namespace std;
class Parser
{

	public:

		Parser(){line_num=0;}
		~Parser(){}
		bool 	load_file(const string &file);
		bool 	update_file(void);
		void dump_ini(void);
		int parse_line(void);
		bool  get_value(const string &key,string &value);
		bool set_value(const char* key,const char* new_value);

	public:
		vector<string > lines;
		map<string,string > key2word;
		int line_num;
	
};	


#endif
