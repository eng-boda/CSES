/*
  Problem Name: Building Roads
  Problem Link: cses.fi/problemset/task/1666/
  Author: EngBoda
  Time Complexity: O(n+m)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define BODA ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0);
#define all(x) x.begin() , x.end()
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define MOD 1000000007
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

int n,m;
vector<vector<int>> adj;
vector<int> vis;

void dfs(int node) {
    vis[node] = true;
    for (auto child : adj[node]) {
        if (!vis[child]) {
            dfs(child);
        }
    }
}

void solve(){
    cin >> n >> m;
    adj.resize(n+1);
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vis.assign(n+1, false);
    int components = 0;
    vector<int> roads;
    for (int i=1;i<=n;i++) {
        if (!vis[i]) {
            components++;
            roads.push_back(i);
            dfs(i);
        }
    }
    cout << components - 1 << '\n';
    for (auto i : roads) {
        if (i == 1) continue;
        cout << i - 1 << ' ' << i << '\n';
    }
}

int main(){
    // Welcome to Boda's world
    BODA;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
  We will count the number of components and then connect them with each other
*/
