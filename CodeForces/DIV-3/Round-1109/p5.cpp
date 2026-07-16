#include <bits/stdc++.h>
using namespace std;

#define int long long

#define loop(i, n) for (int i = 0; i < (n); i++)
#define loop1(i, n) for (int i = 1; i <= (n); i++)
#define loopr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define loopr1(i, n) for (int i = (n); i >= 1; i--)

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ff first
#define ss second

using vi = vector<int>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

#define input(arr, n)          \
    vector<int> arr(n);        \
    loop(i, n) cin >> arr[i];

#define print(arr)             \
    for (auto &x : arr)        \
        cout << x << '\n';

void solveCase() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vi c(n + 1, 0);
    loop1(i, n) {
        char expected = (i % 2 == 1) ? '0' : '1';
        c[i] = (s[i - 1] != expected) ? 1 : 0;
    }

    vi PT0(n + 1, 0), PT1(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        PT0[i] = PT0[i - 1];
        PT1[i] = PT1[i - 1];
        if (c[i] != c[i - 1]) {
            if (c[i] == 0) PT0[i]++;
            else PT1[i]++;
        }
    }

    PT0[1] = 0;
    PT1[1] = 0;

    vi ans; 
    loop(query, q) {
        int l, r, k;
        cin >> l >> r >> k;

        int blocks1 = (c[l] == 1 ? 1 : 0) + (PT1[r] - PT1[l]);
        int blocks0 = (c[l] == 0 ? 1 : 0) + (PT0[r] - PT0[l]);

        int minOps = min(blocks1, blocks0);
        ans.pb(minOps <= k ? 1 : 0);
    }

    for (auto &x : ans) cout << (x ? "YES" : "NO") << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solveCase();
    }
    return 0;
}