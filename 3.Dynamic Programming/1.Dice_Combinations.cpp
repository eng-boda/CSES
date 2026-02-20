/*
  Problem Name: Dice Combinations
  Problem Link: cses.fi/problemset/task/1633
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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

vector<ll> memo;

ll dice(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    if (memo[n] != -1) return memo[n];
    ll ans = 0;
    for (int i=1;i<=6;i++) {
        ans = (ans + dice(n-i)) % MOD;
    }
    memo[n] = ans;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    memo.assign(n+1 , -1);
    cout << dice(n) << '\n';
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
