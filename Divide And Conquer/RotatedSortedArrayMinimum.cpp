// https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
// You are given an array that is rotated randomly. Find the minima in log(n) time
// This approach is not very good with duplicates
#include<iostream>
using namespace std;
int findmin(int a[], int l, int r){
  if(l==r) return a[l]; //trivial case, 1 element
  if(a[r]>a[l]) return a[0]; // trivial case 2- when all elements are sorted in order
  while(r>=l){
    int mid = (l+r)/2;
    if(a[mid]>a[mid+1]) return a[mid+1]; // Inflection check 1- midpoint+1
    if(a[mid-1]>a[mid]) return a[mid]; // Inflection check 2- midpoint
    if(a[mid]>a[0]) { l= mid-1; } else { r=mid+1; } // Move
  }
  return -1; //this exception will never occur
}
int main()
{
      int arr[] = { 5,6,1,2,3,4 };
      cout<<findmin(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
}
