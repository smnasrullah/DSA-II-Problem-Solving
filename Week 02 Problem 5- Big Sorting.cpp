//https://www.hackerrank.com/challenges/big-sorting/problem?isFullScreen=true

#include <bits/stdc++.h>
using namespace std;

bool cmp(const string &a, const string &b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

void merge(vector<string> &A, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<string> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = A[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = A[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (cmp(L[i], R[j]))
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < n1) A[k++] = L[i++];
    while (j < n2) A[k++] = R[j++];
}

void merge_sort(vector<string> &A, int left, int right)
{
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    merge_sort(A, left, mid);
    merge_sort(A, mid + 1, right);

    merge(A, left, mid, right);
}

int main()
{
    int n;
    cin >> n;

    vector<string> A(n);

    for (int i = 0; i < n; i++)
        cin >> A[i];

    merge_sort(A, 0, n - 1);

    for (string s : A)
        cout << s << endl;

    return 0;
}

