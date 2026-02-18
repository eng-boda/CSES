/*
  Problem Name: Message Route
  Problem Link: cses.fi/problemset/task/1667/
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
vector<int> dist;
vector<int> parents;

void solve(){
    cin >> n >> m;
    adj.resize(n+1);
    for (int i=0;i<m;i++) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dist.assign(n+1,-1);
    queue<int> q;
    q.push(1);
    dist[1] = 1;
    parents.assign(n+1,-1);
    parents[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto i : adj[x]) {
            if (dist[i] == -1) {
                dist[i] = dist[x] + 1;
                parents[i] = x;
                q.push(i);
            }
        }
    }
    if (dist[n] == -1) {
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    cout << dist[n] << '\n';
    vector<int> path;
    for (int i=n;i!=0;i=parents[i]) {
        path.push_back(i);
    }
    reverse(all(path));
    for (auto i : path) {
        cout << i << ' ';
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
