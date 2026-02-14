/*
  Problem Name: Missing Numbers
  Problem Link: https://cses.fi/problemset/task/1083/
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
    ll sum = (n*(n+1))/2;
    ll sumOfNums = 0;
    for (int i=0;i<n-1;i++) {
        int num;
        cin >> num;
        sumOfNums += num;
    }
    cout << sum - sumOfNums << '\n';
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
