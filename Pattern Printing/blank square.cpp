/* Printing a square which is only bordered by stars */
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int x=6;
    for(int i=1;i<=x;i++)
    {
      for(int j=1;j<=x;j++)
      {
        if(i==1 || i==6 || j==1 || j==6)   // Specify the sides you need to print
        {
          cout<<"X";
        }
        else {
          cout<<" ";
        }
      }
      cout<<"\n";
    }
    return 0;
}
/*
XXXXXX
X    X
X    X
X    X
X    X
XXXXXX
*/
