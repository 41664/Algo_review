// Sort an array using quick sort
#include<iostream>
using namespace std;
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int partition (int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1);
	for (int j = low; j < high; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int part = partition(arr, low, high);
		quickSort(arr, low, part - 1);
		quickSort(arr, part + 1, high);
	}
}
int main()
{
	int arr[] = {2, 3, 4, 9, 1, 6, 5, 7, 4};
	int n = sizeof(arr)/sizeof(arr[0]);
	quickSort(arr, 0, n-1);
	for(int i=0;i<n;i++)
  {
    cout<<arr[i]<<" ";
  }
	return 0;
}
