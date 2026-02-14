/*
  Problem Name: Counting Rooms
  Problem Link: https://cses.fi/problemset/task/1192
  Author: EngBoda
  Time Complexity: O(n*m)
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

int n , m;
vector<vector<char>> adj;
vector<vector<bool>> vis;

void dfs(int x , int y) {
    if (adj[x][y] == '#') return;
    vis[x][y] = true;
    for (int i=0;i<4;i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && adj[nx][ny] != '#' && !vis[nx][ny]) {
            dfs(nx,ny);
        }
    }
}

void solve(){
    cin >> n >> m;
    adj.resize(n , vector<char>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> adj[i][j];
        }
    }
    vis.assign(n , vector<bool>(m , false));
    int counter = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            if (adj[i][j] == '.' && !vis[i][j]) {
                dfs(i,j);
                counter++;
            }
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
  We will Loop to all points in the grid 
  and if not visited we will use dfs 
  to know the number of dots in the same room 
  and mark them as visited
*/
