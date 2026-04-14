#include <bits/stdc++.h>
using namespace std;


void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}

int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main() {
    fast_io(); 

    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> maze(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
        }
    }

   
    if (maze[0][0] == 1 || maze[n-1][m-1] == 1) {
        cout << "Distance to end: -1\n";
        return 0;
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

      
        if (x == n - 1 && y == m - 1) break;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

           
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0 && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    cout << "Distance to end: " << dist[n-1][m-1] << "\n";

    return 0;
}
