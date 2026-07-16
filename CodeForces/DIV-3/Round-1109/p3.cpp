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


void dfs(int node, vector<bool> &vis, vector<vector<int>> &adj, int id, vector<int> &comp){

    vis[node] = 1;
    comp[node] = id;

    for (auto it : adj[node]){
        if(!vis[it]){
            dfs(it,vis,adj,id,comp);
        }
    }
}

string solve(vi arr,int n, int x, int y) {

    vector<vector<int>> adj(n+1);
    vector<int> comp(n+1,-1);

    loop1(i,n){
       if(i-x >= 1) adj[i].push_back(abs(i-x));
       if(i+x<=n) adj[i].push_back(abs(i+x));
       if(i-y >= 1) adj[i].push_back(abs(i-y));
       if(i+y<=n) adj[i].push_back(abs(i+y));
    }

    vector<bool> vis(n+1,0);
    int id = 1;

    loop1(i,n){
        if(!vis[i]){
            dfs(i,vis,adj,id,comp);
            id++;
        }
    }

    loop(i,n){
        if(comp[i+1] != comp[arr[i]]) return "NO";
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
        int n,x,y;
        cin>>n>>x>>y;

        input(arr,n);

        ans.push_back(solve(arr,n,x,y));
    }
    print(ans);
    return 0;
}