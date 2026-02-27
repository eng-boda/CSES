/*
  Probelm Name: Maximum Subarray Sum
  Problem Link: cses.fi/problemset/task/1643/
  Author: EngBoda
  Time Complexity: O(n)
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

void solve() {
    int n;
    cin >> n;
    vector<ll> x(n);
    for (int i=0;i<n;i++) {
        cin >> x[i];
    }
    ll maxNum = x[0] , ans = x[0];
    for (int i=1;i<n;i++) {
        maxNum = max(x[i] , maxNum + x[i]);
        ans = max(ans, maxNum);
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
