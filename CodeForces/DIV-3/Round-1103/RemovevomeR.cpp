#include <bits/stdc++.h>
using namespace std;

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


int solve(string str) {
    int n = str.length();

    int cnt = 0;

    loop(i,n-1){
        if(str[i] != str[i+1]) cnt++;
    }

    if(cnt == 0) return 1;
    if(cnt == 1) return 2;
    return 1;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<int> ans;

    while (t--) {
        int k;
        cin>>k;
        string str;
        cin>>str;
        ans.push_back(solve(str));    
    }


    print(ans);

    return 0;
}