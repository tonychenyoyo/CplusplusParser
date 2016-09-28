#include <iostream>  
#include <string>  
using namespace std;  
  
string& trim(string &);  
 string& left_trim(string &s)  ; 
 string& right_trim(string &s)   ;
int main()   
{  
    string s = "	Hello World        ";  
    cout << s << " size:" << s.size() << endl;  


	//cout<<"====left======"<<endl;
	
	//cout << left_trim(s) << " size:" << left_trim(s).size() << endl;	
//	cout<<"====right======"<<endl;
	
//	cout << right_trim(s) << " size:" << right_trim(s).size() << endl;	
	
    cout << trim(s) << " size:" << trim(s).size() << endl;  
  
    return 0;  
}  
  
string& trim(string &s)   
{  
    if (s.empty())   
    {  
        return s;  
    }  
    s.erase(0,s.find_first_not_of(" "));  
    s.erase(s.find_last_not_of(" ") + 1);  
    return s;  
}  

string& left_trim(string &s)   
{  
    if (s.empty())   
    {  
        return s;  
    }  
    s.erase(0,s.find_first_not_of(" "));  //从第一个字符开始判断，直到不是空格字符
  //  s.erase(s.find_last_not_of(" ") + 1);  
    return s;  
}  


string& right_trim(string &s)   
{  
    if (s.empty())   
    {  
        return s;  
    }  
  //  s.erase(0,s.find_first_not_of(" "));  
    s.erase(s.find_last_not_of(" ") + 1);  //从最后一个不是空格的开始删除
    return s;  
}  




