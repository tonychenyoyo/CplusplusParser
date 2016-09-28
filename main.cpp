#include<iostream>
#include <fstream>
#include<map>
#include<vector>
#include<string>
#include<list>
#include <string.h>
#include "Parserini.h"

using namespace std;  
  
  int main(void)
  {
  
	  Parser p;
	  
	  string file("example.ini");
	  p.load_file(file);
	  
	  cout<<"================"<<endl;
	  vector < string>::iterator it =p.lines.begin();
	  for(;it!=p.lines.end();++it){
		  cout<<*it<<endl;
	  }
	  
	  cout<<"****************************"<<endl;
  
	  //一行行的解析，把里面的键值对给提取出来
	  p.parse_line();
  /*
	  map <string,string>::iterator iter =p.key2word.begin();
	  for(;iter!=p.key2word.end();++iter){
		  cout<<iter->first<<endl;
	  }
	  cout<<"****************************"<<endl;
  */
  
  
	  
	  p.set_value("Cheese","bluelink");
  
	  
	  if(p.set_value("name","tony"))
	  {
		  //cout<<"add new	value"<<endl;
  
	  }
  
	  
	  if(p.set_value("JAME","yoyo"))
	  {
			  //cout<<"add new	value"<<endl;
	  
	  }
	  
  
	  if(p.set_value("Year","2003"))
	  {
		  //cout<<"add new	value"<<endl;
  
  
	  }
	  
	  
	  string eatvalue;
	  string yearvalue;
	  string food="Cheese";
	  string time="Year";
	  p.get_value(food,eatvalue);
	  cout<<food<<"="<<eatvalue<<endl;
	  p.get_value(time,yearvalue);
	  cout<<time<<"="<<yearvalue<<endl;
  
	  cout<<"@@@@@@@@@@@@@@@@@@@@@@@"<<endl;
	  map <string,string>::iterator iter2 =p.key2word.begin();
	  for(;iter2!=p.key2word.end();++iter2){
		  cout<<iter2->first<<"="<<iter2->second<<endl;
	  }
	  
	  return 0;
  }

