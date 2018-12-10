/*Huffman encoding and decoding
Using either C / C++ / Java / Python, implement the Huffman coding algorithm to construct the Huffman
tree and code each character in a given text message using the Huffman tree.
Optimized approach in C++
Author- @41664 (Ankit)
Output attatched at the end
*/
#include<iostream>
#include<string>
#include<bits/stdc++.h> //STL integeration
//Step1- Build a huffman Tree
//Step 2- Traverse through the values and assign codes to every character -<implement this>
//Step 3- Write a decoding function <Implement this>
using namespace std;
struct MinHeapNode{
  char data;
  int freq;
  MinHeapNode *left, *right;
  //constructor definition
  MinHeapNode(char data, int freq)
  {
    this->data=data;
    this->freq=freq;
    left=right=NULL;
  }
};
//To map each charachter to it's huffman value
map<char, string> codes;
//To store frequency of each character in input data
map<char, int> freq;
//We will implement minHeap by using a priority queue.
//In order to do that we will have to implement a custom comparator
struct compare{
  bool operator()(MinHeapNode* l, MinHeapNode* r)
  {
    return(l->freq>r->freq);
  }
};
void display(struct MinHeapNode* root,string str="")
{
  if(root==NULL)
  {
      return; //checks for null root
  }
  if(root->data!='$') //We assign the top node  a $
  {
      cout<<root->data<<":"<<str<<"\n";
  }
  //recursively call the left and the right nodes
  display(root->left,str+"0");
  display(root->right,str+"1");
}
void store(struct MinHeapNode* root, string str)
{
  //the function follows a similar pattern to display albeit it is used to store in the map
  if(root==NULL)
      return;
  if(root->data!='$')
    codes[root->data]=str;
  store(root->left, str + "0");
  store(root->right, str + "1");
}
//The final priority Queue to store the values in heap nodes according to the algorithm
priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
//The final driver fucntion to put elements into the priority Queue
void HuffmanCodes(int size)
{
    struct MinHeapNode *left, *right, *top;
    //declared the starting nodes
    for (map<char, int>::iterator v=freq.begin(); v!=freq.end(); v++)
        minHeap.push(new MinHeapNode(v->first, v->second)); //Object iteration.
        //Copied from here https://stackoverflow.com/questions/15451287/what-does-iterator-second-mean
        //TL;DR- std::pair object is returned and thus ->first and -> second refers to the pair objects' first and seocnd element
    while (minHeap.size() != 1)
    {
        left = minHeap.top(); //gets the first lowest element
        minHeap.pop();
        right = minHeap.top();//gets the next lowest element
        minHeap.pop();
        //We are creating a new internal node here.
        top = new MinHeapNode('$', left->freq + right->freq);
        //creates a new node as a sum of the children nodes and assumes it is the top node
        top->left = left; //assigns the relation and defines it
        top->right = right;
        minHeap.push(top); //Adds the element to the list
    }
    store(minHeap.top(), "");
}
//A utility function to store the frequencies to the map
void calcFreq(string str, int n)
{
  for (unsigned int i=0; i<str.size(); i++)
        freq[str[i]]++;
}
//Now we need to implement a very basic decode function
//Here is the simple procedure we will follow
//1- if element is 1, move to right
//if element is 0, move to left
//if element is leaf, print
string decode(struct MinHeapNode* root, string s)
{
  string ans=""; //we will keep adding data here
  struct MinHeapNode* curr = root;
  for(unsigned int i=0;i<s.size();i++){
    if (s[i] == '0')
           curr = curr->left;
        else
           curr = curr->right;
    if(curr->left==NULL && curr->right ==NULL) //condition for leaf nodes
    {
      ans+=curr->data;
      curr=root;
    }
  }
  return ans+'\0'; //I'd have better written this in Python.
}
//Driver main function
int main()
{
  string str="thequickbrownfoxjumpedoverthelazydog";
  string coded, decoded;
  calcFreq(str, str.length()); //Size and lenght are both synonymous
  //https://stackoverflow.com/questions/905479/stdstring-length-and-size-member-functions
  //Just a convention thing because C++
  HuffmanCodes(str.length());
  //Printing list of charachters and their frequencies hrough the map
  for (auto v=codes.begin(); v!=codes.end(); v++)
        cout << v->first <<' ' << v->second << endl;
  //https://stackoverflow.com/questions/6963894/how-to-use-range-based-for-loop-with-stdmap
  // Auto variable because of std::pair is returned
  //Now we will encode the string with beauty
  for(auto i:str)
  {
        coded+=codes[i];
      }
  //Here is the encoded string
  cout<<coded<<"\n";
  //Time to decode our string
  decoded=decode(minHeap.top(), coded);
  cout<<decoded;
  return 0;
}
/*Output of this code-
a 10100
b 10001
c 10101
d 0011
e 1110
f 00011
g 10110
h 11110
i 10011
j 01100
k 01101
l 10000
m 11010
n 10111
o 010
p 111110
q 111111
r 0111
t 0010
u 1100
v 10010
w 11011
x 00010
y 00001
z 00000
001011110111011111111001001110101011011000101110101101110111000110100001001100110011010111110111000110101001011100111001011110111010000101000000000001001101010110
thequickbrownfoxjumpedoverthelazydog
[Finished in 2.197s]
Huff.cpp143:1
LFUTF-8C++
masterFetch6 files1 update
*/
