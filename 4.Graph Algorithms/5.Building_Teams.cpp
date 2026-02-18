/*
  Problem Name: Bulding Teams
  Problem Link: https://cses.fi/problemset/task/1668
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

int n , m;
vector<vector<int>> adj;
vector<int> colors;
bool flag = true;

void dfs(int src , int c) {
    colors[src] = c;
    for (auto i : adj[src]) {
        if (colors[i] == -1) {
            dfs(i , 1 - c);
        } else if (colors[i] == colors[src]) {
            flag = false;
        }
    }
}

void solve(){
    cin >> n >> m;
    adj.resize(n+1);
    while(m--) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    colors.assign(n+1, -1);
    for (int i=1;i<=n;i++) {
        if (colors[i] == -1) {
            dfs(i, 0);
        }
    }
    if (!flag) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    for (int i=1;i<=n;i++) {
        cout << colors[i] + 1 << ' ';
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

/* Bipartite Graph */
