#include<bits/stdc++.h>
using namespace std;

long long maxsubarray(long long arr[], long long n)
{
    long long max = arr[0];
    long long current = arr[0];

    for(long long i=1; i<n; i++)
    {
        if(current + arr[i] > arr[i])
            current = current + arr[i];

        else
            current = arr[i];

        if(current > max)
            max = current;
    }
    return max;
}

int main()
{
    long long n; cin>>n;
    long long arr[n];
    for(long long i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    cout<<maxsubarray(arr,n);
    return 0;
}
