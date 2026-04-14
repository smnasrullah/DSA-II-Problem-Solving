//https://www.hackerrank.com/challenges/countingsort2/problem?isFullScreen=true

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int count[100] = {0};
    
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        count[x]++;
    }
    
    bool first = true;
    for(int i = 0; i < 100; i++)
    {
        for(int j = 0; j < count[i]; j++)
        {
            if(!first) cout << " ";
            cout << i;
            first = false;
        }
    }
    
    return 0;
}
