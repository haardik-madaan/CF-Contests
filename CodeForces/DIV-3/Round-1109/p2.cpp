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

string solve(vi arr,int n) {

    int prev = 1;
    int need = 2;
    int buffer = arr[0] - 1;

    for (int i = 1;i<n;i++){
        if(arr[i] >= need){
            buffer+=(arr[i] - need);
        }
        else{
            if(arr[i] + buffer >= need){
                buffer -= (need-arr[i]);
            }   
            else{   
                return "NO";
            }
        }
        arr[i] = need;
        prev = arr[i];
        need = prev+1;
    }
    return "YES";
    
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<string> ans;
    while (t--) {
        int n;
        cin>>n;

        input(arr,n);

        ans.push_back(solve(arr,n));
    }
    print(ans);
    return 0;
}