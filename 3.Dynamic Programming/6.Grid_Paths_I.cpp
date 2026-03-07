/*
  Problem Name: Grid Paths I
  Problem Link: cses.fi/problemset/task/1638/
  Author: EngBoda
  Time Complexity: O(n^2)
*/

// Recursive DP

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
 
int n;
vector<vector<char>> grid;
vector<vector<ll>> memo;
 
ll gridPath(int x , int y) {
    if (x >= n || y >= n || grid[x][y] == '*') return 0;
    if (x == n-1 && y == n-1) return 1LL;
    if (memo[x][y] != -1) return memo[x][y];
    int option1 = gridPath(x+1 , y);
    int option2 = gridPath(x , y+1);
    return memo[x][y] = (option1 + option2)%MOD;
}
 
void solve() {
    cin >> n;
    grid.resize(n , vector<char> (n));
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> grid[i][j];
        }
    }
    memo.assign(n, vector<ll>(n, -1));
    cout << gridPath(0, 0) << '\n';
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

// Iterative DP

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
 
int n;
vector<vector<char>> grid;
vector<vector<ll>> memo;
 
void solve() {
    cin >> n;
    grid.resize(n , vector<char> (n));
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            cin >> grid[i][j];
        }
    }
    if (grid[0][0] == '*') {
        cout << 0 << '\n';
        return;
    }
    vector<vector<int>> dp(n , vector<int> (n , 0));
    dp[0][0] = 1;
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (grid[i][j] != '*') {
                if (i>0) dp[i][j] = (dp[i][j] + dp[i-1][j])%MOD;
                if (j>0) dp[i][j] = (dp[i][j] + dp[i][j-1])%MOD;
            }
        }
    }
    cout << dp[n-1][n-1] << '\n';
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
