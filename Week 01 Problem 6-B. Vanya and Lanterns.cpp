/*
Problem-
https://codeforces.com/problemset/problem/492/B
-------------------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

void merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        A[k] = L[i];
        i++; k++;
    }

    while (j < n2)
    {
        A[k] = R[j];
        j++; k++;
    }
}

void merge_sort(int A[], int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    merge_sort(A, left, mid);
    merge_sort(A, mid + 1, right);

    merge(A, left, mid, right);
}

int main()
{
    int n,l;
    cin >> n >> l;

    int A[n];
    int m = n + 1;
    double B[m];

    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    merge_sort(A, 0, n - 1);

    B[0] = A[0];
    B[m-1] = l - A[n-1];

    for(int i = 1; i < n; i++)
    {
        B[i] = (A[i] - A[i-1]) / 2.0;
    }

    double mx = -1.0;

    for(int i = 0; i < m; i++)
    {
        if(B[i] > mx)
            mx = B[i];
    }

    cout << fixed << setprecision(10) << mx;

    return 0;
}
