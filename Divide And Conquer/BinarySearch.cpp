// Binary search
#include<iostream>
using namespace std;
int binarysearch(int a[], int l, int r, int x){
  while(l<r){
    int m= l+ (r-1) / 2;
    if(a[m]==x) return m;
    else if(a[m] > x) {l=m+1;}
    else if(a[m] < x){r=m-1;}
  }
    return -1;
}
int main(void)
{
  int a[]= {1,2,3,4,5,6,7,8,9};
  cout<< binarysearch(a, 0, sizeof(a)/ sizeof(a[0]) -1,10 );
  return 0;
}
