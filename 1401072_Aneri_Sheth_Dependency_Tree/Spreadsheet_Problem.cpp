/*
Written by Aneri Sheth

This is an implementation of dependency tree
*/
#include <iostream>
#include <list>
#include <stack>
using namespace std;



class graph
{
    int V;    
 	list<Cell> *adj;
 	void topologicalSortUtil(Cell v, bool visited[], stack<Cell> &Stack);
 	stack FormulaStack
public:
    graph(int V);   
 	void addEdge(Cell v, Cell w);
 	void topologicalSort();
};




 
 class Cell
 {
 	public:	
 	string formula;
 	int value;
 };

 

 

void graph::topologicalSortUtil(Cell v, bool visited[], stack<Cell> &Stack)  
{
    
    visited[v.index] = true;
    
 	list<int>::iterator i;
    for (i = adj[v.index].begin(); i != adj[v.index].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
 
    if(v.formula)
    Stack.push(v.formula);
    else
    Stack.push(v.value);
}


 

void graph::topologicalSort()  
{
    stack<Cell> Stack;
 
    
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
   
    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);
 
  
    while (Stack.empty() == false)
    {
        cout << Stack.top().index << " ";
        Stack.pop();
    }
}



graph::graph(int V)
{
    this->V = V;
    adj = new list<Cell>[V];
}



 
void graph::addEdge(Cell v, Cell w)
{
    adj[v.index].push_back(w); 
}
 

int main()      
{
    graph g(4);       
    g.addEdge(0, 3);  
    g.addEdge(0, 2);  
    g.addEdge(2, 3);  
 
    cout << "Following is a Topological Ordering of the given graph \n";
    g.topologicalSort();
 
    return 0;
}
