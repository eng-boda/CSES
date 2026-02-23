/*
  Problem Name: Movie Festival
  Problem Link: cses.fi/problemset/task/1629/
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
#define INF 1e9
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

void solve() {
    int n;
    cin >> n;
    vector<pair<ll,ll>> movies(n);
    for (int i=0;i<n;i++) {
        cin >> movies[i].second >> movies[i].first;
    }
    sort(all(movies));
    int counter = 0 , lastEnd = 0;
    for (int i=0;i<n;i++) {
        if (movies[i].second >= lastEnd) {
            counter++;
            lastEnd = movies[i].first;
        }
    }
    cout << counter << '\n';
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

/*Sort the pairs according to the end time of the movie*/
