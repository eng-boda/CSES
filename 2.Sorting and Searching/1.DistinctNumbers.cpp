/*
  Problem Name: Distinct Numbers
  Problem Link: https://cses.fi/problemset/task/1621/
  Author: EngBoda
  Time Complexity: O(nLogn)
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
    int n;
    cin >> n;
    set<ll> distincitNumbers;
    for (int i=0;i<n;i++) {
        ll a;
        cin >> a;
        distincitNumbers.insert(a);
    }
    cout << distincitNumbers.size() << '\n';
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
  Set is one of STLs that insert only distincit numbers on sorted way
  insert in set is O(log n)
  we can use unordered_set to make insert O(1)
*/
