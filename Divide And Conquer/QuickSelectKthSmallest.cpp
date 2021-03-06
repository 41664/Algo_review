// Find the kth smallest element of an unsorted aray using Quick Select method
#include<iostream>
#include<climits>
using namespace std;
int partition(int arr[], int l, int r);
int kthSmallest(int arr[], int l, int r, int k)
{
	if (!(k > 0 && k <= r - l + 1)){return INT_MAX;}
		int pos = partition(arr, l, r);
		if (pos-l == k-1)
			return arr[pos];
		if (pos-l > k-1)
			return kthSmallest(arr, l, pos-1, k);
    else
		  return kthSmallest(arr, pos+1, r, k-pos+l-1);
}
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
int partition(int arr[], int l, int r)
{
	int x = arr[r], i = l-1;
	for (int j = l; j <= r - 1; j++)
	{
		if (arr[j] <= x)
		{
      i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	return i+1;
}
int main()
{
	int arr[] = {12, 3, 5, 7, 4, 19, 26};
	int n = sizeof(arr)/sizeof(arr[0]), k = 1;
	cout << kthSmallest(arr, 0, n-1, k);
	return 0;
}
