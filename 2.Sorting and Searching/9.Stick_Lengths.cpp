/*
  Problem Name: Stick Lengths
  Problem Link: cses.fi/problemset/task/1074/
  Author: EngBoda
  Time Complexity: O(n log n)
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
#define MAX 1000001
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void solve() {
    int n;
    cin >> n;
    vector<ll> p(n);
    for (int i=0;i<n;i++) {
        cin >> p[i];
    }
    sort(all(p));
    ll target = p[0];
    if (n%2 == 0) target = p[n/2 - 1];
    else target = p[n/2];
    ll ans = 0;
    for (int i=0;i<n;i++) {
        ans += abs(p[i] - target);
    }
    cout << ans << '\n';
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
