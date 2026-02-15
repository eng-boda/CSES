/*
  Problem Name: Apartments
  Problem Link: https://cses.fi/problemset/task/1084/
  Author: EngBoda
  Time Complexity: O(n log n + m log m)
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
    int n , m;
    cin >> n >> m;
    ll k;
    cin >> k;
    vector<ll> a(n) , b(m);
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    sort(all(a));
    for (int i=0;i<m;i++) {
        cin >> b[i];
    }
    sort(all(b));
    int counter = 0;
    int p1 = 0 , p2 = 0;
    while (p1<n && p2<m) {
        if (abs(b[p2] - a[p1]) <= k) {
            counter++;
            p2++;
            p1++;
        } else if (a[p1] > b[p2]) {
            p2++;
        } else {
            p1++;
        }
    }
    cout << counter << '\n';
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
  First we will sort the 2 arrays
  then we will use two pointers to check in O(n+m)
*/
