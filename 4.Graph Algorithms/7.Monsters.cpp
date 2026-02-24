/*
  Problem Name: Monsters
  Problem Link: cses.fi/problemset/task/1194/
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
#define INF 1e9
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
char dir[] = {'U', 'D', 'L', 'R'};

int n , m;
vector<vector<char>> grid;
vector<vector<int>> monsters_dist;
vector<vector<int>> dist;
vector<vector<int>> parent;

void solve() {
    cin >> n >> m;
    grid.resize(n , vector<char>(m));
    queue<pair<int, int>> monsters;
    queue<pair<int, int>> A;
    monsters_dist.assign(n , vector<int>(m , INF));
    dist.assign(n , vector<int>(m , INF));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'M') {
                monsters.push({i, j});
                monsters_dist[i][j] = 0;
            }
            if (grid[i][j] == 'A') {
                A.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    while (!monsters.empty()) {
        auto [x,y] = monsters.front();
        monsters.pop();
        for (int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && monsters_dist[nx][ny] == INF) {
                monsters_dist[nx][ny] = monsters_dist[x][y] + 1;
                monsters.push({nx, ny});
            }
        }
    }
    parent.assign(n , vector<int>(m , -1));
    while (!A.empty()) {
        auto [x,y] = A.front();
        A.pop();
        if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
            YES;
            string path = "";
            while (grid[x][y] != 'A') {
                int d = parent[x][y];
                path += dir[d];
                x -= dx[d];
                y -= dy[d];
            }
            reverse(all(path));
            cout << path.size() << '\n';
            cout << path << '\n';
            return;
        }
        for (int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == '.' && dist[nx][ny] == INF && dist[x][y] + 1 < monsters_dist[nx][ny]) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = i;
                A.push({nx, ny});
            }
        }
    }
    NO;
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
