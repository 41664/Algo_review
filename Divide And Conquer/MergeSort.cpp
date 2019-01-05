#include<iostream>
using namespace std;
void swap(int *a, int *b){
  int t=*a;
  *a=*b;
  *b=t;
}
void merge(int arr[],int l,int r, int m)
{
  // copy the arrays
  int n1= m-l+1;
  int n2= r-m;
  int L[n1],R[n2];
  for(int i=0;i<n1;i++) L[i]=arr[l+i];
  for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
  //now compare
  int i=0;
  int j=0;
  int k=l;
  while(i< n1 && j<n2)
  {
    if(L[i]<=R[j]) { arr[k]= L[i]; i++;}
    else { arr[k]= R[j];j++;}
    k++;
  }
  // Remaining elements
  while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int low, int high){
  if(low<high){
  int mid= (low+high) /2;
  mergesort(arr,low,mid);
  mergesort(arr,mid+1,high);
  merge(arr,low,high,mid);
  }
}
int main()
{
  int arr[] = {12, 11, 13, 5, 6, 7};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  mergesort(arr, 0, arr_size - 1);
  for (int i=0; i < arr_size; i++)
        printf("%d ", arr[i]);
  return 0;
}
