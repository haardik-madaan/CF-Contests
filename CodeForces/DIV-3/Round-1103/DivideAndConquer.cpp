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

string solve(pii vec) {
    int a = vec.ff;
    int b = vec.ss;
    if(a < b) return "NO";
    if(a%b == 0) return "YES";
    return "NO";
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    pii vec;

    vector<string> ans;
    while (t--) {
        cin>>vec.ff;
        cin>>vec.ss;
        
        ans.push_back(solve(vec));

    }

    print(ans);

    return 0;
}