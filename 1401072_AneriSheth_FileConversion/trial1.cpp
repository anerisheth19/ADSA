// #include <stdafx.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main () {
 ifstream fin( "hi.bin" ) ;
 ofstream fout( "new.txt" ) ;
  std::string line ;
  while( getline( fin, line, '.' ) )
    {
       std::size_t LINE_SZ = 75 ;
 
        while( line.size() > LINE_SZ ) // if longer than LINE_SZ, split it 
        {
            fout << line.substr( 0, LINE_SZ ) << '\n' ;
            line = line.substr(LINE_SZ) ;
        }
 
        fout << line << '\n' ;
    }
}
