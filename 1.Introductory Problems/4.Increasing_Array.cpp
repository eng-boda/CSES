/*
  Problem Name: Increasing Array
  Problem Link: cses.fi/problemset/task/1094/
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

void solve(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    ll ans = 0;
    for (int i=1;i<n;i++) {
        int diff = a[i] - a[i-1];
        if (diff < 0) {
            ans += abs(diff);
            a[i] = a[i-1];
        }
    }
    cout << ans << '\n';
}

int main(){
    // Welcome to Boda's world
    BODA;
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
/*
  if a[i] < a[i-1] make a[i] = a[i-1] and make ans += the differnce between them
*/
