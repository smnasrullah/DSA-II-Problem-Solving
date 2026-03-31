//https://www.hackerrank.com/challenges/countingsort1/problem?isFullScreen=true

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count[100];
    for(int i = 0; i < 100; i++)
    {
        count[i] = 0;
    }

    for(int i = 0; i < n; i++)
    {
        int x = arr[i];
        count[x] = count[x] + 1;
    }

    for(int i = 0; i < 100; i++)
    {
        cout << count[i];
        if(i < 99) cout << " ";
    }

    return 0;
}
