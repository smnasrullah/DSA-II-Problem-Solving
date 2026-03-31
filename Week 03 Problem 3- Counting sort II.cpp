//https://www.hackerrank.com/challenges/countingsort2/problem?isFullScreen=true

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int arr[1000];

    int count[100] = {0};

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        count[arr[i]]++;
    }

    for(int i = 0; i < 100; i++)
    {
        while(count[i]--)
        {
            cout << i << " ";
        }
    }

    return 0;
}
