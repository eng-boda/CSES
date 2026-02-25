/*
  Problem Name: Sum of Two Values
  Problem Link: cses.fi/problemset/task/1640/
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
#define INF 1e9
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<pair<ll,int>> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(all(a));
    int l = 0 , r = n - 1;
    while (l<r) {
        if (a[l].first + a[r].first == x) {
            cout << a[l].second << ' ' << a[r].second << '\n';
            return;
        } else if (a[l].first + a[r].first > x) {
            r--;
        } else {
            l++;
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
