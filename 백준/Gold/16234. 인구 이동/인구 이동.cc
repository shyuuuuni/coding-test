/**
 * @file 백준-16234-인구 이동-시뮬레이션.cpp
 * @author shyuuuuni (seunghyun4525@gmail.com)
 * @brief 백준 시뮬레이션 연습 문제 풀이
 * @date 2022-07-01
 * 
 */
#include <bits/stdc++.h>

using namespace std;

int n;
int l, r;
int board[50][50];

// BFS
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int vis[50][50];
int calc[50 * 50];
int n_union[50 * 50];
int union_cnt;
queue<pair<int, int> > q;

void reset() {
    memset(vis, 0, sizeof(vis));
    memset(calc, 0, sizeof(calc));
    memset(n_union, 0, sizeof(n_union));
    union_cnt = 0;
    while (!q.empty()) {
        q.pop();
    }
    return;
}

int bfs() {
    int result = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        int cur = board[x][y];
        q.pop();
        result++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || n <= nx || n <= ny) continue;
            if (vis[nx][ny] != 0) continue;

            int nxt = board[nx][ny];
            if (l <= abs(cur - nxt) && abs(cur - nxt) <= r) {
                vis[nx][ny] = union_cnt;
                calc[union_cnt] += board[nx][ny];
                q.push(make_pair(nx, ny));
            }
        }
    }

    return result;
}

int main(void) {
    // init
    int t = 0;
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    while (1) {
        reset();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (vis[i][j] == 0) {
                    q.push(make_pair(i, j));
                    vis[i][j] = ++union_cnt;
                    calc[union_cnt] += board[i][j];
                    n_union[union_cnt] = bfs();
                }
            }
        }
        if (union_cnt == n*n) {
            break;
        } else {
            t++;
            for (int i = 1; i <= union_cnt; i++) {
                if (n_union[i] == 0) {
                    cout << "div_by_zero";
                } else {
                    calc[i] = calc[i] / n_union[i];
                }
            }
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    board[i][j] = calc[vis[i][j]];
                }
            }
        }
    }

    cout << t;
}