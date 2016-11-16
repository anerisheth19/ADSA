#include<iostream>
#include<fstream>
#include<string>

using namespace std;
int main () 
{
	char a='4',b='7',c='9',d='3';
	int t =0;
	int r = t+a+(b<<8) + (c<<16) + (d<<24);
	cout<<r;
}


