//https://www.hackerrank.com/challenges/runningtime/problem?isFullScreen=true

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[n];

    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    int shifts = 0;

    for(int k=1;k<n;k++)
    {
        int t =A[k];
        int i=k-1;

        while(i>=0 && A[i]>t)
        {
            A[i+1] = A[i];
            shifts++;
            i--;
        }
        A[i+1] = t;
    }

    cout << shifts;

    return 0;
}
