#include<bits/stdc++.h>

using namespace std;
#define n 12

void swapnum(int *arr, int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}
int main()
{
	//freopen ("output.txt","w",stdout);
	//freopen ("input.txt", "r", stdin);
	//int arr[12] = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	int arr[12] = {2, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 0};
	int mid = 0, start = 0, end= n-1;
	while(mid <= end)
	{
		switch(arr[mid]){

			case 0:
				swapnum(arr, mid, start);
				start++;
				mid++;
				break;
			case 1:
				mid++;
				break;
			case 2:
				swapnum(arr, mid, end);
				end--;
		}
	}

	for(int i =0; i<n ; i++)
	{
		cout<<arr[i]<<", ";
	}
	cout<<"\b\b";
	getchar();

	return 0;
}
