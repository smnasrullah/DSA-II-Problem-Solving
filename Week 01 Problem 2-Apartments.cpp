#include<bits/stdc++.h>
using namespace std;

long long partition(long long arr[], long long s, long long e)
{
    long long pivot = arr[s];
    long long count = 0;
    for(long long i =s+1; i<=e; i++)
    {
        if(arr[i]<=pivot)
        {
            count= count + 1;
        }
    }
    long long p_index= s+count;

    swap(arr[s],arr[p_index]);
    long long i=s,j=e;
    while(i<p_index && j>p_index)
    {
        while(arr[i]<=pivot)
        {
            i++;
        }
        while(arr[j]>pivot)
        {
            j--;
        }

        if(i<p_index && j>p_index)
        {
            swap(arr[i],arr[j]);
            i++;j--;
        }
    }
    return p_index;
}

void quicksort(long long arr[],long long s, long long e)
{
    if(s>=e) return;

    long long p = partition(arr,s,e);

    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main()
{
    long long n,m,k;
    cin>>n>>m>>k;

    long long a1[n];
    for(int i=0;i<n;i++)
    {
        cin>>a1[i];
    }
    quicksort(a1,0,n-1);

    long long a2[m];
    for(int i=0;i<m;i++)
    {
        cin>>a2[i];
    }
    quicksort(a2,0,m-1);

    int i = 0, j = 0, result = 0;
    while (i < n && j < m)
    {
        if (a2[j] < a1[i] - k)
        {
            j++;
        }
        else if (a2[j] > a1[i] + k)
        {
            i++;
        }
        else
        {
            result++;
            i++;
            j++;
        }
    }
    cout<<result;

    return 0;
}
