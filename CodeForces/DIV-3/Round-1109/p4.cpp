#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> a(n + 1), pre(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pre[i] = pre[i - 1] + a[i];
        }

        vector<int> b(m);
        for (auto &x : b) cin >> x;
        sort(b.begin(), b.end());

        int ans = 0, prev = 0;
        for (int c : b) {
            int segSum = pre[c] - pre[prev];
            ans += llabs(segSum);
            prev = c;
        }
        ans += (pre[n] - pre[prev]);

        cout << ans << '\n';
    }
    return 0;
}