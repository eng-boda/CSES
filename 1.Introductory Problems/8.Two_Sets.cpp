/*
  Problem Name: Two Sets
  Problem Link: cses.fi/problemset/task/1092/
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
#define INF 1e18
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void solve() {
    ll n;
    cin >> n;
    ll sum = (n * (n + 1)) / 2;
    if (sum%2 != 0) {
        NO;
        return;
    }
    ll target = sum / 2;
    set<int> set1 , set2;
    for (int i=n;i>0;i--) {
        if (target - i >= 0) {
            set1.insert(i);
            target -= i;
        } else {
            set2.insert(i);
        }
    }
    YES;
    cout << set1.size() << '\n';
    for (auto i : set1) {
        cout << i << ' ';
    }
    cout << '\n';
    cout << set2.size() << '\n';
    for (auto i : set2) {
        cout << i << ' ';
    }
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
