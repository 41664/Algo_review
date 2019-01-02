/* Printing a rhombus
A rhombus has all sides with same size but they start diagonally  */
#include<bits/stdc++.h>
using namespace std;
int main()
{
  int x=6;
  for(int i=1;i<=x;i++)
  {
    for(int j=1;j<=i;j++)
      cout<<" ";
    for(int j=1;j<=x;j++)
      cout<<"X";
    cout<<"\n";
  }
  return 0;
}

/*
XXXXXX
 XXXXXX
  XXXXXX
   XXXXXX
    XXXXXX
     XXXXXX
*/
