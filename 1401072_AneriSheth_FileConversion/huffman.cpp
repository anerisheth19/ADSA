// C++ program for Huffman coding
#include<iostream>
#include<fstream>
#include<vector>
#include <bits/stdc++.h>

using namespace std;
vector<int> answer;

 
// A Huffman tree node
struct MinHeapNode
{
    char data;                // One of the input characters
    unsigned freq;             // Frequency of the character
    MinHeapNode *left, *right; 
 
    MinHeapNode(char data, unsigned freq)
    {
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
 
// For comparison of two heap nodes (needed in min heap)
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->freq > r->freq);
    }
};
 
// Prints huffman codes from the root of Huffman Tree.
void printCodes(struct MinHeapNode* root, string str)
{
    if (!root)
        return;
 
    if (root->data != '$')
        cout << root->data << ": " << str << "\n";
 
    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}
 
// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void HuffmanCodes(char data[], int freq[], int size)
{
    struct MinHeapNode *left, *right, *top;
 
    // Create a min heap & inserts all characters of data[]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
 
    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1)
    {
        // Extract the two minimum freq items from min heap
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
 		top = new MinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        minHeap.push(top);
    }
 
    // Print Huffman codes using the Huffman tree built above
    printCodes(minHeap.top(), "");
}
vector<int> result1(int a)
{
    while(a>0)
    {
        answer.push_back(a%2);
        a=a/2;
    }
    return answer;
}
int main()
{
    ifstream cin("Paragraph.txt");
    ofstream cout("frequency.txt");
    int count[200]={0};
    string a;
    getline(cin,a);
    cout<<a<<endl;
    char arr[58];
    int frq[58];
    int i;
    for(i=0;i<a.size();i++)
        count[(int)a.at(i)]++;
    int j;
    for(i=65;i<=122;i++)
    frq[i-65]=count[i];
    for(i=0;i<a.size();i++)
    {
        result1((int)a.at(i));
        for(j=0;j<answer.size();j++)
            cout<<answer.at(j);
        if(a.at(i)==' ')
            cout<<" ";
        answer.clear();
    }    
    for(i=65;i<=122;i++)
        arr[i-65]=char(i);
     
        
     int size = sizeof(arr) / sizeof(arr[0]);
 
    HuffmanCodes(arr, frq, size);
//	string s='';  
} 
//}


