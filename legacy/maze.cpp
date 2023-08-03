// the maze
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// BFS
bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    int m = maze.size(), n = maze[0].size();
    int i, j, k, x, y;

    // four direction
    vector<vector<int>> dir = {{1,0}, {0,1}, {0,-1}, {-1,0}};

    // BFS queue
    queue<vector<int>> q;

    // already visited
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    q.push(start);

    while (!q.empty()) {
        i = q.front()[0]; // x
        j = q.front()[1]; // y
        q.pop();

        if (i == destination[0] && j == destination[1]) {
            return true;
        }

        // four direction
        // next point
        for (k=0; k<4; k++) {
            x = i;
            y = j;

            while (x+dir[k][0] >= 0
            && x+dir[k][0] < m
            && y+dir[k][1] >= 0
            && y+dir[k][1] < n // not border
            && maze[x+dir[k][0]][y+dir[k][1]] == 0) {
                x += dir[k][0];
                y += dir[k][1];
            }

            // next is border, stop
            if (!visited[x][y]) {
                q.push({x,y});
                visited[x][y] = true;
            }
        }
    }
    return false;
}

// DFS
bool found = false;
int m, n;
vector<vector<int>> dir = {{1,0}, {0, 1}, {-1,0}, {0,-1}};
bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    m = maze.size(), n = maze[0].size();
    // int i, j, k, x, y;

    // stack<vector<int>> s;
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // s.push(start);

    // while (!s.empty()) {
    //     i = s.top()[0];
    //     j = s.top()[1];
    //     s.pop();


    //     x = i;
    //     y = j;
    //     for(k=0; k<4; k++) {
    //         while (x + dir[k][0] >=0
    //         && x + dir[k][0] < m
    //         && y + dir[k][1] >= 0
    //         && y + dir[k][1] < n
    //         && maze[x + dir[k][0]][y + dir[k][1]] == 0) {
    //             x += dir[k][0];
    //             y += dir[k][1];
    //         }
    //     }

    //     // border
    //     if (!visited[x][y]) {
    //         s.push({x, y});
    //         visited[x][y] = true;
    //     }

    // }

    return false;
}

void dfs(vector<vector<int>>& maze, vector<int> start, vector<int>& destination, vector<vector<bool>>& visited) {
    if (found) {
        return;
    }

    int i = start[0], j = start[1], k, x, y;

    // check end
    if (i == destination[0] && j == destination[1]) {
        found = true;
        return;
    }

    for(k=0; k<4; k++) {
        while (x + dir[k][0] >=0
        && x + dir[k][0] < m
        && y + dir[k][1] >= 0
        && y + dir[k][1] < n
        && maze[x + dir[k][0]][y + dir[k][1]] == 0) {
            x += dir[k][0];
            y += dir[k][1];
        }
    }

    // border
    if (!visited[x][y]) {
        visited[x][y] = true;
        dfs(maze, {x,y}, destination, visited);
    }
}