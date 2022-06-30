/**
 * @file 백준-16236-아기상어-시뮬레이션.cpp
 * @author shyuuuuni (seunghyun4525@gmail.com)
 * @brief 백준 시뮬레이션 연습 문제 풀이
 * @date 2022-07-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <bits/stdc++.h>

using namespace std;

// N x N 크기의 공간
int N;
int board[20][20];

// 남은 물고기 수
int rest;

// 아기 상어 크기
int baby_level;

// 아기 상어가 먹은 물고기 수
int n_eat;

// 아기상어 위치, 시간
pair<pair<int, int>, int> baby;

// BFS
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};
int vis[20][20];

void init();
void reset();

void init() {
    // init
    cin >> N;
    rest = 0;
    baby_level = 2;
    n_eat = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                baby.first.first = i;
                baby.first.second = j;
                baby.second = 0;
                board[i][j] = 0;
            } else if (0 < board[i][j]) {
                rest++;
            }
        }
    }
    reset();
}

void reset() {
    // reset vis
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            vis[i][j] = 0;
        }
    }
    vis[baby.first.first][baby.first.second] = 1;
    return;
}

bool valid(int x, int y) {
    return (0 <= x && 0 <= y && x < N && y < N);
}

void printstat() {
    cout << "init at :" << baby.first.first << " " << baby.first.second << " exp: " << n_eat << " / " << baby_level << ", " << baby.second <<"\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == baby.first.first && j == baby.first.second) {
                cout << "X";
            } else {
                cout << board[i][j];
            }
            cout << " ";
        }
        cout << "\n";
    }
}

int main(void) {
    init();

    while (1) {
        if (rest == 0) {
            break;
        }

        // BFS 큐
        reset();
        queue<pair<pair<int, int>, int> > q;
        vector<pair<int, int> > result_set;
        int flag = 0;
        q.push(baby);
        // printstat();

        while(!q.empty()) {
            int cur_x = q.front().first.first;
            int cur_y = q.front().first.second;
            int t = q.front().second;
            int level = board[cur_x][cur_y];

            q.pop();

            if (level % 9 != 0 && level < baby_level) {
                if (flag == 0) {
                    flag = t;
                }
                if (flag < t) {
                    continue;
                } else {
                    result_set.push_back(make_pair(cur_x, cur_y));
                }
            }

            for (int i = 0; i < 4; i++) {
                int nx = cur_x + dx[i];
                int ny = cur_y + dy[i];
                if (!valid(nx,ny)) {
                    continue;;
                } else if (vis[nx][ny]) {
                    continue;
                } else if (baby_level < board[nx][ny]) {
                    continue;
                }

                vis[nx][ny] = 1;
                q.push(make_pair(make_pair(nx, ny), t + 1));
            }
        }

        if (flag == 0) {
            break;
        } else {
            // find answer
            sort(result_set.begin(), result_set.end());

            int x = result_set[0].first, y = result_set[0].second;
            board[x][y] = 0;
            rest--;
            baby = make_pair(make_pair(x, y), flag);
            n_eat++;
            if (n_eat == baby_level)
            {
                baby_level++;
                n_eat = 0;
            }
        }
    }

    int result = baby.second;
    cout << result;

    return 0;
}