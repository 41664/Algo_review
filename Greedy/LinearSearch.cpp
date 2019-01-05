// Linear Search
#include<iostream>
using namespace std;
int linearsearch(int a[], int l, int r, int x){
  for(int i=l;i<r;i++){
    if(a[i]==x){ return i+1;}
          }
    return -1;
  }
int main(void)
{
  int a[]= {1,2,3,4,5,6,7,8,9};
  cout<< linearsearch(a, 0, sizeof(a)/ sizeof(a[0]) -1,2 );
  return 0;
}
