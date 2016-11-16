#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//Global variables declared
int cost[10][10]; //array for maximum size of graph (V,E)
int i,j,k,n,stack[10],top,v,visit[10],visited[10];
 
int main()
{
int m;
cout <<"Enter number of vertices";
cin >> n;
cout <<"Enter number of edges";
cin >> m;
cout <<"\nWrite the graph edges \n";
for(k=1;k<=m;k++)
{
	cin >>i>>j;
	cost[i][j]=1;
}
 
cout <<"Enter the source node(vertex)";
cin >>v;
cout <<"DFS Traversal: \n";
cout << v <<" ";
visited[v]=1;
k=1;
while(k<n)
{
for(j=n;j>=1;j--)
	if(cost[v][j]!=0 && visited[j]!=1 && visit[j]!=1)
	{
		visit[j]=1;
		stack[top]=j;
		top++;
	}
	v=stack[--top];
	cout<<v << " ";
	k++;
	visit[v]=0; visited[v]=1;
}
}
