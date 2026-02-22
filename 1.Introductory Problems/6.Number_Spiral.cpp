/*
  Problem Name: Number Spiral
  Problem Link: cses.fi/problemset/task/1071/
  Author: EngBoda
  Time Complexity: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define BODA ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0);
#define all(x) x.begin() , x.end()
#define YES cout << "YES" << '\n'
#define NO cout << "NO" << '\n'
#define MOD 1000000007
#define INF 1e9
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};
 
void solve() {
    ll y , x;
    cin >> y >> x;
    ll z = max(y, x);
    ll ans = 0;
    if (z%2 == 0) {
        if (z == y) ans = z * z - x + 1;
        else ans = (z-1)*(z-1) + y;
    } else {
        if (z == x) ans = z * z - y + 1;
        else ans = (z-1)*(z-1) + x;
    }
    cout << ans << '\n';
}
 
int main() {
    // Welcome to Boda's world
    BODA;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
