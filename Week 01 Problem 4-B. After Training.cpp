#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<pair<long long, long long>> baskets;
    for (long long i = 1; i <= m; i++) {
        long long dist = abs(2*i - m - 1);
        baskets.push_back({dist, i});
    }
    sort(baskets.begin(), baskets.end());

    vector<long long> ans(m + 1, 0);
    for (long long j = 0; j < m; j++) {
        long long basket_idx = baskets[j].second;
        if (j + 1 <= n) {
            ans[basket_idx] = (n - j - 1) / m + 1;
        }
    }

    for (long long i = 1; i <= m; i++) {
        cout << ans[i];
        if (i < m) cout << " ";
    }
    cout << endl;
    return 0;
}
