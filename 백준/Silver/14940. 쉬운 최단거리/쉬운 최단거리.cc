/**
 * @file 백준-14940-쉬운 최단거리-그래프.cpp
 * @author shyuuuuni (seunghyun4525@gmail.com)
 * @brief 백준 그래프 연습문제 풀이
 * @date 2022-07-01
 * @copyright Copyright (c) 2022
 * 간단한 BFS 연습 문제이다.
 */
#include <bits/stdc++.h>

using namespace std;

int n, m;
pair<int, int> stt;
int board[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main(void) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                stt = make_pair(i, j);
                board[i][j] = 0;
            } else if (board[i][j] == 1) {
                board[i][j] = -1;
            }
        }
    }

    queue<pair<int, int> > q;
    q.push(stt);

    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int dist = board[x][y];
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] != -1) continue;

            board[nx][ny] = dist + 1;
            q.push(make_pair(nx, ny));
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}