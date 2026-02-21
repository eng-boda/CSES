/*
  Problem Name: Restaurant Customers
  Problem Link: cses.fi/problemset/task/1619/
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
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> time;
    int minN = 1e9 , maxN = 0;
    for (int i=0;i<n;i++) {
        int st , ed;
        cin >> st >> ed;
        time.push_back({st,1});
        time.push_back({ed,-1});
    }
    sort(all(time));
    int curr = 0 , ans = 0;
    for (auto i : time) {
        curr += i.second;
        ans = max(ans,curr);
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

/*Think in partial sum*/
