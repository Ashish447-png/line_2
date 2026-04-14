#include <bits/stdc++.h>
using namespace std;

struct Node {
    int x, y, g, h, f; 
    bool operator>(const Node& other) const {
        return f > other.f; 
    }
};

int n, m;
int maze[1005][1005]; 
int dist[1005][1005];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

inline int heuristic(int x, int y, int ex, int ey) {
    return abs(x - ex) + abs(y - ey);
}

int aStar(int sx, int sy, int ex, int ey) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    
    for(int i=0; i<n; i++) 
        for(int j=0; j<m; j++) dist[i][j] = 1e9;

    int h = heuristic(sx, sy, ex, ey);
    pq.push({sx, sy, 0, h, h});
    dist[sx][sy] = 0;

    while (!pq.empty()) {
        Node cur = pq.top();
        pq.pop();

        if (cur.x == ex && cur.y == ey) return cur.g;
        if (cur.g > dist[cur.x][cur.y]) continue; 

        for (int i = 0; i < 4; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && maze[nx][ny] == 0) {
                int new_g = cur.g + 1;
                if (new_g < dist[nx][ny]) {
                    dist[nx][ny] = new_g;
                    int new_h = heuristic(nx, ny, ex, ey);
                    pq.push({nx, ny, new_g, new_h, new_g + new_h});
                }
            }
        }
    }
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); // Fast I/O
    
    if(!(cin >> n >> m)) return 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> maze[i][j];

    int ans = aStar(0, 0, n-1, m-1);
    if (ans == -1) cout << "No Path\n";
    else cout << "Shortest Path Length: " << ans << "\n";
}
