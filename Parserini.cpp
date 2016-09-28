/*************************************************************************
	> File Name: parseini.cpp
	> Author: chenyuanfa
	> Mail: tonychen5250@163.com 
	> Created Time: Mon 26 Sep 2016 05:54:38 PM CST
 ************************************************************************/

#include<iostream>
#include <fstream>
#include<map>
#include<vector>
#include<string>
#include<list>
#include <string.h>
#include "Parserini.h"

using namespace std;

bool 	Parser::load_file(const string &file)
{
	bool status =false;
	char  buffer[100]={0};
	
	ifstream in(file.c_str());
	if(! in.is_open())
	{ 
	 	cout << "Error opening file"<<endl ;
		return status;
		
	}  
	status=true;
	while (!in.eof())
	{	
		string str;
		//第一种方式
	//	in.getline (buffer,sizeof(buffer));  
	//	string str(buffer);

		//第二种方式
		getline(in,str,'\n');

		//第三种方式
		
	//	getline(in,str);
	//	lines.insert(make_pair(str,num));
		lines.push_back(str);
		++line_num;
	}
	in.close();
	return status;
}

bool 	Parser::update_file(void)
{
	
}

string& left_trim(string &s) 
{
	if (s.empty())   
	{  
        	return s;  
	}  
	s.erase(0,s.find_first_not_of(" ")); //去除空格
	s.erase(0,s.find_first_not_of("	")); //去除TAB键
	
}

string& right_trim(string &s) 
{
	if (s.empty())   
	{  
        	return s;  
	}  
	s.erase(s.find_last_not_of(" ")+1);  //去除空格
	s.erase(s.find_last_not_of("	")+1);  //去除TAB键
	
}


string& trim(string &s)   
{  
	left_trim(s);
	right_trim(s);
    	return s;  
}  
/*
char* TrimSpace(char* name)
{
	// remove starting space or tab
	char* start_pos = name;
	while ( (*start_pos == ' ') || (*start_pos == '\t') )
	{
		start_pos++;
	}

	if (strlen(start_pos) == 0)
		return NULL;

	// remove ending space or tab
	char* end_pos = name + strlen(name) - 1;
	while ( (*end_pos == ' ') || (*end_pos == '\t') )
	{
		*end_pos = 0;
		end_pos--;
	}

	int len = (int)(end_pos - start_pos) + 1;
	if (len <= 0)
		return NULL;

	return start_pos;
}
*/

void Parser::dump_ini(void)
{
/*
   for(std::map<CStdString, IniSection>::iterator kvp=m_iniData.begin();kvp!=m_iniData.end();++kvp)
    {
       std::cout << "[" << kvp->first.c_str() << "]\n";

      for(std::map<CStdString, IniVal>::iterator ivp=kvp->second.begin();ivp!=kvp->second.end();++ivp)
        {
        	std::cout << ivp->first.c_str() << "=" << ivp->second.strVal.c_str() << "\n";

        }
        std::cout << "\n";
    }
   */
}


int Parser::parse_line(void)
{
	char buffer[50]={0};
	for(vector <string>::iterator it =lines.begin();it!=lines.end();++it)
	{
		int pos=(*it).find("=");

		int value_end=(*it).find(";");
		int length=value_end-pos;
		if(pos>=0 && value_end>=0)//说明这个应该是
		{
			string key(*it,0,pos-1);
			key=trim(key);
			string value(*it,pos+1,length-1);
			value=trim(value);
			key2word.insert(make_pair(key,value));
		}else if(pos>=0){
			//说明只有=号没有;号
		}else if(value_end>=0){
			//说明没有=号，只有;，算注释
		}else{
			//两者都没有就不用管了
		}
		
	}
	
}

bool  Parser::get_value(const string &key,string &value)
{

	bool status=false;
	
	map <string,string>::iterator it =key2word.begin();
	for(;it!=key2word.end();++it){

		if(it->first==key){
			cout<<"found............."<<endl;
			value=it->second;
			status=true;
		}
	
	}
	return status;

	
}

bool Parser::set_value(const char* key,const char* new_value)
{
	bool status=false;
	map <string,string>::iterator it =key2word.find(key);
	if(it!=key2word.end()){
	it->second=new_value;
		status=true;
		
	}else{
		cout<<"it is a new key"<<endl;
		key2word.insert(make_pair(key,new_value));
	}
	return true;
	
}


