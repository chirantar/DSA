#include<bits/stdc++.h>

using namespace std;

void alternateSort(int* arr, int n)
{
	sort(arr, arr+n, greater<int>());
	int i =0, j=n-1;

	while(i<j)
	{
		cout<<arr[i]<<", ";
		cout<<arr[j]<<", ";
		i++;j--;
	}

}

int main()
{
	//freopen ("output.txt","w",stdout);
	//freopen ("input.txt", "r", stdin);
	int n = 6;
	int arr[] = {1, 12, 4, 6, 7, 10};
	alternateSort(arr,n);
	getchar();

	return 0;
}
