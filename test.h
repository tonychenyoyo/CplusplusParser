/*************************************************************************
	> File Name: test.h
	> Author: chenyuanfa
	> Mail: tonychen5250@163.com 
	> Created Time: Mon 26 Sep 2016 05:55:38 PM CST
 ************************************************************************/

#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<list>
using namespace std;


class Parse
{
	public:
//静态成员函数不能属于某个对象
	bool  load_file(const string &file);
	bool update_file(void);

	int parse_line(void);
	void dump_ini(void);

	bool  get_value(const string &key,string &value);

	bool set_value(const char* key,const char* new_value);
//	private:
		vector <string> lines;
		map<string,string> key2word;
		int line_number;
	

};
