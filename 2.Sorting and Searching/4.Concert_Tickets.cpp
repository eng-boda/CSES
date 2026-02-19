/*
  Problem Name: Concert Tickets
  Problem Link: cses.fi/problemset/task/1091/
  Author: EngBoda
  Time Complexity: O(m log n)
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
    multiset<ll> prices;
    vector<ll> customers(m);
    for (int i=0;i<n;i++) {
        ll p;
        cin >> p;
        prices.insert(p);
    }
    for (int i=0;i<m;i++) {
        cin >> customers[i];
    }
    for (int i=0;i<m;i++) {
        auto it = prices.upper_bound(customers[i]);
        if (it == prices.begin()) {
            cout << -1 << '\n';
        } else {
            it--;
            cout << *it << '\n';
            prices.erase(it);
        }
    }
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
  Use Multiset to make the prices sorted and the delete O(log n)
  Use Upper Bound to get the first number bigger than the customer budget
  then erase the number from the multiset and make the same operation with the other customers
*/
