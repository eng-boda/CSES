/*
  Problem Name: Minimizing Coins
  Problem Link: cses.fi/problemset/task/1634/
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

vector<int> coins;
vector<int> memo;

int minimizeCoins(int x) {
    if (x == 0) return 0;
    if (x < 0) return INF;
    if (memo[x] != -1) return memo[x];
    int ans = INF;
    for (auto i : coins) {
        int res = minimizeCoins(x - i);
        if (res != INF) {
            ans = min(ans, res+1);
        }
    }
    memo[x] = ans;
    return ans;
}

void solve() {
    int n , x;
    cin >> n >> x;
    coins.resize(n);
    for (int i=0;i<n;i++) {
        cin >> coins[i];
    }
    memo.assign(x+1 , -1);
    int ans = minimizeCoins(x);
    if (ans == INF) {
        cout << -1 << '\n';
        return;
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
