// Insertion Sort Analysis for a sequence of random numbers
// Created by Aneri Sheth 1401072

#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>

using namespace std;

//main function 
int main()
{
	ofstream out; //file management for analysis
	out.open("insertion_values.csv");
	int key; //index for the values declared
	int n; //total number of elements in the sort
	for(n =1; n<=10000; n+=50) 
	{
		int a[n]; //array of n numbers
		for(int x=0;x<n;x++) 
		{
			a[x] = rand()%n; //random function generator in C++
		} 
		clock_t begin = clock(); //time for the code to execute in the beginning
		//Insertion Sort Algorithm
		for(int i =1; i<n; i++)
		{
			for(int j =i; j>=1; j--)
			{
				if(a[j] < a[j-1])
				{
					// Swapping 
					key = a[j];
					a[j] = a[j-1];
					a[j-1] = key;
				}
				else 
				{
					break;
				}
			}
		}
	clock_t end = clock(); // time for the code to stop 
	double time =((double)end-begin)/CLOCKS_PER_SEC; //formulae for conversion of the time
	out<<n<<","<<time<<"\n";
}
}

