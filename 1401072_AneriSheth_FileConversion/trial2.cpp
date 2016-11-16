#include <iostream>
#include <string>
#include <bitset>
#include<fstream>

//Program to convert a text file into binary file
using namespace std;

int main()
{
char letter = ' ';
string filename= " ";

cout << "\t**Text To Binary Convertor**\n\n";


    cout << "Enter filename: ";

    getline (cin, filename, '\n');

    ifstream infile;
    infile.open(filename.c_str());
    if(infile.fail()){
        cout << "File not found\n"; exit(1);
    }
    else {
        cout << "Converting file..." << endl;
    }
    cout << "\nThe binary value for " << filename << " is \n";
    
 
    filename += "_.bin";

    for (unsigned int filenamePosition = 0; filenamePosition < filename.size(); ++filenamePosition)
	{

        letter = filename[filenamePosition];

        bitset <8> binary(letter);

        cout << binary;
        }



return 0;
}
