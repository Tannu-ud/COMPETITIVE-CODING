#include<iostream>
using namespace std;
int main()
{
	int n,i;
	int target;
	int arr[n];
	cout<<"Enter the size of array: ";
	cin>>n;
	cout<<"Enter the sorted array: ";
	for(i =0; i<n ; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter target: ";
	cin>>target;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] >= target)
		{
			cout << i;
			return 0;
		}
	}
	cout << n;
	return 0;
}
