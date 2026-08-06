#include<iostream>
using namespace std;
int main()
{
	int i,n;
	int target;
	cout<<"Enter the no. of array: ";
	cin>>n;
	int arr[n];
	cout<<"Enter sorted array: ";
	for (i=0; i<n; i++)
	{
		cin>>arr[i];
	}
	cout<<"Enter target: ";
	cin>>target;
	int low=0, high=n-1;
	while(low <= high)
	{
		int mid = (low + high)/2;
		if (arr[mid]==target)
		{
			cout<<mid;
			return 0;
		}
		else if (arr[mid]<target)
		{
			low = mid+1;
		}
		else
		{
			high = mid-1;
		}
	}
	cout<<low;
	return 0;
}
