/*
  Problem Name: Labyrinth
  Problem Link: https://cses.fi/problemset/task/1193/
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
vector<vector<char>> grid;
vector<vector<int>> dist;
vector<vector<char>> parents;

bool isValid(int x , int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void solve(){
    cin >> n >> m;
    pair<int,int> A , B;
    grid.resize(n , vector<char>(m));
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                A = {i, j};
            } else if (grid[i][j] == 'B') {
                B = {i, j};
            }
        }
    }
    queue<pair<int,int>> q;
    q.push(A);
    dist.assign(n , vector<int>(m , -1));
    dist[A.first][A.second] = 0;
    parents.resize(n , vector<char>(m));
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        for (int i=0;i<4;i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (isValid(nx,ny) && grid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx,ny});
                parents[nx][ny] = dir[i];
            }
        }
    }
    if (dist[B.first][B.second] == -1) {
        NO;
        return;
    }
    string paths = "";
    pair<int,int> curr = B;
    while (curr != A) {
        char move = parents[curr.first][curr.second];
        paths.push_back(move);
        if (move == 'U') curr.first++;
        else if (move == 'D') curr.first--;
        else if (move == 'R') curr.second--;
        else if (move == 'L') curr.second++;
    }
    YES;
    cout << paths.size() << '\n';
    reverse(all(paths));
    cout << paths << '\n';
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
