#ifndef stringm
#define stringm
#include<string.h>
#include<iostream>
using namespace std;
class mstring{
private:
	char* ptr;
	int size;
public:
	char* c_str();
	int length();
	//
	mstring operator+=(char*);//done
	mstring operator+=(char);//done
	mstring operator+=(mstring);//done
	mstring operator=(mstring);//done
	mstring operator=(char*);//done
	mstring operator=(char);//done
	//
	mstring();
	mstring(char*);
	
};
ostream& operator<<(ostream&,mstring);
#endif