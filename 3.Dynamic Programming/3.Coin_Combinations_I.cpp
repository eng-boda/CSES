/*
  Problem Name: Coin Combinations I
  Problem Link: cses.fi/problemset/task/1635
  Author: EngBoda
  Time Complexity: O(n*x)
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

int n;
vector<ll> coins;
vector<ll> memo;

ll coinsCombinations(ll x) {
    if (x == 0) return 1;
    if (x < 0) return 0;
    if (memo[x] != -1) return memo[x];
    ll totalWays = 0;
    for (int i=0;i<n;i++) {
        totalWays = (totalWays%MOD + coinsCombinations(x - coins[i])%MOD)%MOD;
    }
    return memo[x] = totalWays;
}

void solve() {
    int x;
    cin >> n >> x;
    coins.resize(n);
    for (int i=0;i<n;i++) {
        cin >> coins[i];
    }
    memo.assign(x+1, -1);
    cout << coinsCombinations(x) << '\n';
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
