#include"mystring.h"
//Methods
char* mstring::c_str(){
	return ptr;
}
//
int mstring::length(){
	return size;
}
//Constructors
mstring::mstring(){
	size=0;
}
//
mstring::mstring(char* cont){
	size=strlen(cont);
	ptr=new char[size+1];
	for(int i=0;i<size;i++){
		ptr[i]=cont[i];
	}
	ptr[size]='\0';
}
//
//operators
mstring mstring::operator +=(char letter){
	if(size>0){
		char* tmp=new char[size];
		for(int i=0;i<size;i++){
			tmp[i]=ptr[i];
		}
		delete[] ptr;
		ptr=new char[size+2];
		for(int i=0;i<size;i++){
			ptr[i]=tmp[i];
		}
		delete[] tmp;
		ptr[size]=letter;
		ptr[size+1]='\0';
		size++;
	}else{
		size=1;
		ptr=new char[2];
		ptr[0]=letter;
		ptr[1]='\0';
	}
	return (*this);
}
//
mstring mstring::operator+=(char* str){
	if(size>0){
	char* tmp=new char[size];
	for(int i=0;i<size;i++){
		tmp[i]=ptr[i];
	}
	delete[] ptr;
	ptr=new char[size+strlen(str)+1];
	for(int i=0;i<size;i++){
		ptr[i]=tmp[i];
	}
	delete[] tmp;
	for(int i=0;i<strlen(str);i++){
		ptr[i+size]=str[i];
	}
	size=size+strlen(str);
	ptr[size+1]='\0';
	}else{
		(*this).operator+=(str[0]);
		char* tmp=new char[strlen(str)-1];
		for(int i=1;i<strlen(str);i++){
			tmp[i-1]=str[i];
		}
		(*this).operator+=(tmp);
		delete[] tmp;
	}
	return (*this);
}
//
mstring mstring::operator=(char letter){
	if(size>0){
		delete[] ptr;
	}
	size=1;
	ptr=new char[2];
	ptr[0]=letter;
	ptr[1]='\0';
	return (*this);
}
//
mstring mstring::operator=(char* str){
	if(size>0){
		delete[] ptr;
	}
	size=strlen(str);
	ptr=new char[size+1];
	for(int i=0;i<size;i++){
		ptr[i]=str[i];
	}
	ptr[size]='\0';
	return (*this);
}
//
mstring mstring::operator+=(mstring m1){
	(*this).operator+=(m1.c_str());
	return (*this);
}
//
mstring mstring::operator=(mstring m1){
	(*this).operator=(m1.c_str());
	return (*this);
}
///
ostream& operator<<(ostream& chan,mstring m1){
	for(int i=0;i<m1.length();i++){
		chan<<m1.c_str()[i];
	}
	chan.flush();
	return chan;
}