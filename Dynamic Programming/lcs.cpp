#include<iostream>
#include<bits/stdc++.h>
#include<cstring>
//Longest common subsequence problem
//Different from longest common substring problem. We need to find the longest common subsequence in 2 strings
//A subsequence is something which is in order not necessarily contagiously allocated
//lcs(a,b) = (lcs(a-a[m],b-b[n]) if the last characters are same
//lcs(a,b) = max of lcs(a-a[m],b) and (a,b-b[n])
using namespace std;
int max(int x,int y)
{
  return(x>y)?x:y;
}
//We use a tabulation mechanism in order to faciliatet this
int lcs(char *X, char *Y, int m, int n)
{
  int L[m+1][n+1];
  //We are constructing a table for lookup
  for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
  int index=L[m][n];
  char lcs[index+1];
  lcs[index]='\0';
  int i=m,j=n;
  while(i<0 && j>0)
  {
    if (X[i-1] == Y[j-1])
      {
          lcs[index-1] = X[i-1]; // Put current character in result
          i--; j--; index--;     // reduce values of i, j and index
      }

      // If not same, then find the larger of two and
      // go in the direction of larger value
      else if (L[i-1][j] > L[i][j-1])
         i--;
      else
         j--;
  }
  cout<< lcs;
}
int main()
{
  char X[] = "ABC";
  char Y[] = "ABCD";
  int m = strlen(X);
  int n = strlen(Y);
  lcs(X, Y, m, n);
  return 0;
}
