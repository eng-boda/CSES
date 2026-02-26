/*
  Problem Name: Shortest Routes II
  Problem Link: cses.fi/problemset/task/1672/
  Author: EngBoda
  Time Complexity: O(n^3)
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

int n , m , q;
vector<vector<ll>> dist;

void solve() {
    cin >> n >> m >> q;
    dist.resize(501 , vector<ll>(501));
    for (int i=1;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    while (m--) {
        ll a , b , c;
        cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
        dist[b][a] = min(dist[b][a], c);
    }
    for (int k=1;k<=n;k++) {
        for (int i=1;i<=n;i++) {
            for (int j=1;j<=n;j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    while (q--) {
        int a , b;
        cin >> a >> b;
        if (dist[a][b] == INF) cout << -1 << '\n';
        else cout << dist[a][b] << '\n';
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
