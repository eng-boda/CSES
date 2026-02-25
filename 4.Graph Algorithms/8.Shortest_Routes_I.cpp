/*
  Problem Name: Shortest Routes I
  Problem Link: cses.fi/problemset/task/1671/
  Author: EngBoda
  Time Complexity: O(m log n)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define BODA ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0);
#define all(x) x.begin() , x.end()
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define MOD 1000000007
#define INF 1e18
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

int n , m;
vector<vector<pair<ll, ll>>> adj;
vector<bool> vis;
vector<ll> dist;

void dijkstra(int src) {
    priority_queue<pair<ll,int> , vector<pair<ll,int>> , greater<pair<ll,int>> > pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [cost , node] = pq.top();
        pq.pop();
        if (vis[node]) continue;
        vis[node] = true;
        for (auto [to , w] : adj[node]) {
            if (dist[to] > cost + w) {
                dist[to] = cost + w;
                pq.push({dist[to], to});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--) {
        int a , b , c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist.assign(n+1 , INF);
    vis.assign(n + 1 , false);
    dijkstra(1);
    for (int i=1;i<=n;i++) {
        cout << dist[i] << ' ';
    }
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
