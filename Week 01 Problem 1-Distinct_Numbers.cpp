#include<bits/stdc++.h>
using namespace std;

void merge(int A[], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
    {
        L[i] = A[l + i];
    }
    for(int i = 0; i < n2; i++)
    {
        R[i] = A[mid + 1 + i];
    }
    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }
    while(i < n1)
        A[k++] = L[i++];
    while(j < n2)
        A[k++] = R[j++];
}

void mergeSort(int A[], int l, int r){
    if(l < r){
        int mid = (l + r) / 2;
        mergeSort(A, l, mid);
        mergeSort(A, mid + 1, r);
        merge(A, l, mid, r);
    }
}

int main(){
    int n;
    cin >> n;
    int A[n];
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    mergeSort(A, 0, n - 1);

    int number = 0;
    for(int i = 0; i < n - 1; i++){
        if(A[i] != A[i+1])
            number = number + 1;
    }
    cout << number + 1;
    return 0;
}
