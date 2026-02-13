/*
  Problem Name: Weird Algorithm
  Problem Link: https://cses.fi/problemset/task/1068/
  Author: EngBoda
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define BODA ios_base::sync_with_stdio(0); cin.tie(0),cout.tie(0);
#define all(x) x.begin() , x.end()
#define YES cout << "Yes" << '\n'
#define NO cout << "No" << '\n'
#define MOD 1000000007
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void solve(){
    ll n;
    cin >> n;
    while(n!=1) {
        cout << n << ' ';
        if (n%2 == 0) n/=2;
        else n = 3*n + 1;
    }
    cout << n << ' ';
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
