/*
  Problem Name: Round Trip
  Problem Link: cses.fi/problemset/task/1669/
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
vector<bool> visited;
vector<int> parent;
int startNode = -1 , endNode = -1;

bool dfs(int node , int p) {
    visited[node] = true;
    for (auto child : adj[node]) {
        if (!visited[child]) {
            parent[child] = node;
            if (dfs(child , node)) return true;
        } else if (child != p) {
            startNode = node;
            endNode = child;
            return true;
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    adj.resize(n+1);
    while (m--) {
        int u , v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    visited.assign(n+1, false);
    parent.assign(n+1, -1);
    for (int i=1;i<=n;i++) {
        if (!visited[i]) {
            if (dfs(i, -1)) {
                vector<int> path;
                path.push_back(endNode);
                for (int curr=startNode;curr!=endNode;curr=parent[curr]) {
                    path.push_back(curr);
                }
                path.push_back(endNode);
                cout << path.size() << '\n';
                for (auto p : path) {
                    cout << p << ' ';
                }
                cout << '\n';
                return;
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    // Welcome to Boda's world
    BODA;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*Check if there is a cycle or not*/
