//https://ww.hackerrank.com/challenges/quicksort1/problem?isFullScreen=true

#include<bits/stdc++.h>
using namespace std;

void partition(int arr[], int n)
{
    int pivot = arr[0];

    int left[1000], right[1000];
    int l = 0, r = 0;

    for(int i = 1; i < n; i++)
    {
        if(arr[i] < pivot)
            left[l++] = arr[i];
        else
            right[r++] = arr[i];
    }

    for(int i = 0; i < l; i++)
        cout << left[i] << " ";

    cout << pivot << " ";

    for(int i = 0; i < r; i++)
        cout << right[i] << " ";
}

int main()
{
    int n; cin >> n;
    int arr[1000];

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    partition(arr, n);

    return 0;
}
