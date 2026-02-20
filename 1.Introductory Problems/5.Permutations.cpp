/*
  Problem Name: Permutations
  Problem Link: cses.fi/problemset/task/1070/
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

void solve() {
    int n;
    cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << '\n';
        return;
    }
    for (int i=2;i<=n;i+=2) {
        cout << i << ' ';
    }
    for (int i=1;i<=n;i+=2) {
        cout << i << ' ';
    }
    cout << '\n';
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
