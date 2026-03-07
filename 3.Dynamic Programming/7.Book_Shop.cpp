/*
  Problem Name: Book Shop
  Problem Link: cses.fi/problemset/task/1158/
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
#define INF 1e18
#define MAX 1000001
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

int n , x;
vector<int> h , s;

void solve() {
    cin >> n >> x;
    h.resize(n);
    s.resize(n);
    for (int i=0;i<n;i++) cin >> h[i];
    for (int i=0;i<n;i++) cin >> s[i];
    vector<int> dp(x+1 , 0);
    for (int i=0;i<n;i++) {
        for (int j=x;j>=h[i];j--) {
            dp[j] = max(dp[j] , s[i] + dp[j-h[i]]);
        }
    }
    cout << dp[x] << '\n';
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
